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

1. Build for production with `npm run webpack:production`
2. Push 2 files in `./build` (namely: `Index.js` and `index.html`) to the `username.github.io` repository
3. Go to `https://username.github.io`
