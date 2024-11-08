import os
import sys
import analyzer


def analsis_main(FuncList):
    analyzer.Init (FuncList)
    analyzer.ReadShmQueue ()

    while (True):
        UncoveredFuncs = analyzer.GetUncoeredFuncs ()
        print (UncoveredFuncs)

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage: python analysis.py [input]")
    else:
        analsis_main(sys.argv[1])
