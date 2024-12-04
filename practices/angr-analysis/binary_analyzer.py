import sys
import angr
import claripy

class BinaryAnalyzer:
    def __init__(self, binary_path):
        self.binary_path = binary_path
        self.project = angr.Project(binary_path, auto_load_libs=False)

    def ShowProjAttr (self):
        print (dir(self.project))
        print (dir(self.project.analyses))

    def ShowBinaryInfo (self):
        print("\n@@@@ Binary Information: ")
        print(f"Architecture: {self.project.arch}")
        print(f"Entry Point: {hex(self.project.entry)}")

        print(f"\n@@@ Functions defined in {self.binary_path}:")
        cfg = self.project.analyses.CFGFast()
        for addr, func in cfg.kb.functions.items():
            print(f"Function: {func.name} at {hex(addr)}")

    def ShowFuncInfo (self, func_name):
        cfg = self.project.analyses.CFGFast()
        func = cfg.kb.functions.function(name=func_name)
        print(f"\n@@ {func_name} function address: {hex(func.addr)}")
        print("Basic blocks in {func_name}:")
        for block in func.blocks:
            print(f"Block starts at: {hex(block.addr)}")

    def RunSymbolic(self, target_addr):
        print("\n@@@@ Symbolic Execution: ")
        symbolic_arg = claripy.BVS("argv1", 64)
        state = self.project.factory.entry_state(args=[self.binary_path, symbolic_arg])
        simul_mgr = self.project.factory.simulation_manager(state)

        simul_mgr.explore(find=target_addr)
        if simul_mgr.found:
            solution_state = simul_mgr.found[0]
            password = solution_state.posix.dumps(0)
            print(f"The password is: {password}")
        else:
            print("No solution found.")

    def RunSymbolicAuto (self):
        def is_target(state):
            try:
                output = state.posix.dumps(1)
                return b"Access Granted" in output
            except Exception:
                return False
        print("\n@@@@ Symbolic Execution: ")
        symbolic_arg = claripy.BVS("argv1", 64)
        state = self.project.factory.entry_state(args=[self.binary_path, symbolic_arg])
        simul_mgr = self.project.factory.simulation_manager(state)

        simul_mgr.explore(find=is_target)
        if simul_mgr.found:
            solution_state = simul_mgr.found[0]
            password = solution_state.posix.dumps(0)
            print(f"The password is: {password}")
        else:
            print("No targets found.")

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage: python binary_analyzer.py <binary_path>")
        sys.exit(1)

    binary_path = sys.argv[1]
    analyzer = BinaryAnalyzer(binary_path)
    analyzer.ShowProjAttr ()
    analyzer.ShowBinaryInfo ()
    analyzer.ShowFuncInfo ('main')
    analyzer.RunSymbolic (0x400801)
    analyzer.RunSymbolicAuto ()

    