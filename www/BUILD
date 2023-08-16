load("@aspect_rules_js//js:defs.bzl", "js_library")
load("@npm//:defs.bzl", "npm_link_all_packages")
load("@npm//www:webpack-cli/package_json.bzl", "bin")

npm_link_all_packages(
    name = "node_modules",
)

js_library(
    name = "lib",
    srcs = [
        "package.json",
        ".babelrc",
    ] + glob([
        "src/**/*.tsx",
        "src/**/*.ts",
        "src/**/*.css",
        "src/**/*.scss",
        "public/**/*",
    ]),
    deps = [
        ":node_modules/@babel/core",
        ":node_modules/@babel/preset-env",
        ":node_modules/@babel/preset-react",
        ":node_modules/@babel/preset-typescript",
        ":node_modules/@svgr/webpack",
        ":node_modules/babel-loader",
        ":node_modules/css-loader",
        ":node_modules/html-webpack-plugin",
        ":node_modules/mini-css-extract-plugin",
        ":node_modules/react",
        ":node_modules/react-dom",
        ":node_modules/sass",
        ":node_modules/sass-loader",
        ":node_modules/style-loader",
    ],
)

bin.webpack_cli(
    name = "www-bundle",
    srcs = [
        ":lib",
        ":webpack.config.js",
    ],
    outs = [
        "dist/index.html",
        "dist/main.css",
        "dist/main.js",
    ],
    args = [
        "--config webpack.config.js",
    ],
    chdir = package_name(),
    log_level = "debug",
)
