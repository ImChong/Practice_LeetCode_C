'''
FilePath     : \Practice_LeetCode_C\.vscode\build.py
Author       : Chong Liu
CreateDate   : 2023-11-04 00:23:08
LastEditors  : Chong Liu
LastEditTime : 2024-01-24 00:17:57
=================================================================================
Copyright (c) 2023 by Chong Liu, All Rights Reserved.
=================================================================================
Description  : python 编译指令，用于编译 ${fileDirname}/main.c
    如果存在 ${fileDirname}/src 文件夹，则编译 ${fileDirname}/src/*.c 和 ${fileDirname}/main.c
    如果不存在 ${fileDirname}/src 文件夹，则编译 ${fileDirname}/main.c
'''
import sys              # sys provides information about constants, functions and methods of the Python interpreter
import os               # os provides functions for interacting with the operating system
import subprocess       # subprocess allows you to spawn new processes, connect to their input/output/error pipes, and obtain their return codes

if __name__ == "__main__":
    print("Start compiling ...")

    # sys.argv[0] = ${workspaceFolder}/.vscode/build.py
    gccPath = sys.argv[1]               # sys.argv[1] = gcc path
    workspacePath = sys.argv[2]         # sys.argv[2] = ${workspaceFolder}
    filePath = sys.argv[3]              # sys.argv[3] = ${fileDirname}
    mainPath = filePath + "/main.c"     # ${fileDirname}/main.c

    if not os.path.isfile(mainPath):                # check if main.c exists
        print("[" + mainPath + "] not exists, compilation failed!")
    elif not os.path.isdir(filePath + "/cfg"):      # check if cfg folder exists
        print("cfg folder not exists, compilation failed!")
    elif not os.path.isdir(filePath + "/inc"):      # check if inc folder exists
        print("inc folder not exists, compilation failed!")
    elif not os.path.isdir(filePath + "/src"):      # check if src folder exists
        print("src folder not exists, compilation failed!")
    else:   # if all checks passed, then compile
        print("file checks finished successfully! continue...")
        # compile command
        cmd = [
            gccPath,
            "-fdiagnostics-color=always",
            "-I" + workspacePath + "/F01_Common_Functions/inc/common_def/",
            "-I" + workspacePath + "/F01_Common_Functions/inc/",
            "-I" + filePath + "/cfg/",
            "-I" + filePath + "/inc/",
            workspacePath + "/F01_Common_Functions/src/*.c",
            filePath + "/src/*.c",
            mainPath,
            "-g",
            "-o",
            filePath + "/main.exe"
        ]

        # execute compile command
        try:
            print("gcc compilation subprocess.runnning ...")
            result = subprocess.run(cmd, capture_output=True, text=True)

            # compiled successfully
            if result.returncode == 0:
                print("subprocess.run compilation finished successfully!")

            # compiled failed
            else:
                print("An error occurred during compilation:")
                print(result.stderr)
                print("subprocess.run compilation failed!")

        # compiled failed
        except Exception as error:
            print("An error occurred during compilation:")
            print(str(error))
            print("subprocess.run compilation failed!")

    # compile finished
    print("End compiling ...\n")
