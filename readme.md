**install code runner ext**

**settings.json**
```
{
    "code-runner.runInTerminal": true,
    "code-runner.fileDirectoryAsCwd": true,
    "code-runner.executorMap": {
        "cpp": "g++ $fileName -o $fileNameWithoutExt.out && ./$fileNameWithoutExt.out"
    },
    "editor.renderWhitespace": "all"
}
```

**build with makefile:**
```
"cpp": "make && ./main.exe"
```

**To execute task:**
- Ctrl + Alt + P; 
- Enter 'Run Task'; 
- Choose the corresponding label in tasks.json