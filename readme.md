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

**Day 1**
```
ReverseList: easy
Middle node of list: easy, dummy head;
PalindromeList: easy, get length; reverse first half; compare first & second.
*DeleteNthEnd: medium, define condition: fast - slow == n && fast != null; handle the boundary: len < n; len == n; len > n
Rotate list right: medium, get list len and mod
*SortList: medium, recursivly sort half list of passed in list(partition, depth first), then merge, note: how to the the second half
MergeKList: hard, base on merge two list.
```

**Day n**
```

```