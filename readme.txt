settings.json

{
    "code-runner.runInTerminal": true,
    "code-runner.executorMap": {
        "cpp": "g++ $fileName -o $fileNameWithoutExt.out && ./$fileNameWithoutExt.out"
    }
}

with makefile:
"cpp": "make && ./main.exe"

install code runner ext