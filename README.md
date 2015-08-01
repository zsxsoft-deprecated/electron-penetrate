electron-penetrate
======

**Windows Only**

**NodeJS 0.12.0+**

**Tested under Electron 0.30.2**

It used Win32 API to make your Electron window penetrable. 

A new branch of https://github.com/zsxsoft/nw-penetrate .

![Snapshot](http://project.zsxsoft.com/electron-penetrate/snapshot.gif)

### Installion
```bash 
$ npm install electron-penetrate
```

### Usage
First, you should open ``transparent`` in ``package.json``
```javascript
var browserWindow = new BrowserWindow({
    transparency: true
});
```

Then, set a unique ``document.title`` dynamically (like ``Math.random()``). 
```javascript
var tranResult = require("electron-penetrate").penetrate(document.title);
console.log(tranResult);
```


## 中文

它调用了Win32API来让你的Electron窗口可被鼠标穿过。

首先打开它的transparent选项；其次，你需要设置一个独一无二的窗口标题。我觉得``Math.random()``是个不错的选择呢。