# SHared APpartement bookKEEping

##  Run & Test locally

### 1. Compile ReasonML to Javascript with Bucklescript
```
[root@d777a1dfc437 shapkee]# pwd
/src/shapkee
[root@d777a1dfc437 shapkee]# npm start
```

### 2. Bundle and serve with webpack
```
[root@d777a1dfc437 shapkee]# pwd
/src/shapkee
[root@d777a1dfc437 shapkee]# npm run server
```

### 3. Visit `http://localhost:3001`

See `package.json` for details:
```
"server": "webpack-dev-server --host 0.0.0.0 --port 3001 --disable-host-check"
```


## Deploy to github.io

### 1. Copy 2 file to the XYZ github repository

```
[k@mbp: ~/src/shapkee ] ls -la ./build/
-rw-r--r--   1 k  staff  1242308 Jul 28 14:46 Index.js
-rw-r--r--   1 k  staff      248 Jul 28 14:46 index.html
```

### 2. Visit XYZ.github.io
