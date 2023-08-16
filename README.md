# Bazel

Bazel for TypeScript, we need to take care of those things.
Layout:

- pnpm-workspace.yaml: Contains all JavaScript packages in the monorepo.

```yaml
packages:
  - www
  - <project name>
```

- pnpm-lock.yaml: Holds all our JavaScript dependency trees.
- WORKSPACE: Bazel file contains references to external dependencies required for the building process.

```yaml
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
    name = "aspect_rules_js",
    sha256 = "928ba25fa82cfe7983f89118677413dc74dbc5d0360fa969da07ff22a9306052",
    strip_prefix = "rules_js-1.15.1",
    url = "https://github.com/aspect-build/rules_js/archive/refs/tags/v1.15.1.tar.gz",
)

load("@aspect_rules_js//js:repositories.bzl", "rules_js_dependencies")

rules_js_dependencies()

load("@rules_nodejs//nodejs:repositories.bzl", "DEFAULT_NODE_VERSION", "nodejs_register_toolchains")

nodejs_register_toolchains(
    name = "nodejs",
    node_version = DEFAULT_NODE_VERSION,
)


load("@aspect_rules_js//npm:npm_import.bzl", "npm_translate_lock")

# Read the pnpm-lock.yaml file to automate creation of remaining npm_import rules
npm_translate_lock(
    name = "npm",
    data = [
        "//react-project-1:package.json"
    ],
    pnpm_lock = "//:pnpm-lock.yaml",
    verify_node_modules_ignored = "//:.bazelignore"
)

load("@npm//:repositories.bzl", "npm_repositories")

npm_repositories()
```

- BUILD: Bazel file that holds some global building rules for the monorepo.
- .bazelignore: Specify directories within the workspace that you want Bazel to ignore.

Under `www` project:

- package.json: Specifys the dependencies we need in the web.
- `pnpm i` is required after we modified the package.json
- webpack.config.js: Like a normal webpack plugin.

```js
const path = require("path");
const HtmlWebpackPlugin = require("html-webpack-plugin");
const MiniCssExtractPlugin = require("mini-css-extract-plugin");

module.exports = {
  entry: "./src/index.js",
  output: {
    filename: "main.js",
    path: path.resolve(__dirname, "dist"),
  },
  plugins: [
    new HtmlWebpackPlugin({
      template: path.join(__dirname, "public", "index.html"),
    }),
    new MiniCssExtractPlugin(),
  ],
  devServer: {
    static: {
      directory: path.join(__dirname, "output"),
    },
    port: 3000,
  },
  module: {
    // exclude node_modules
    rules: [
      {
        test: /\.(js|jsx)$/,
        exclude: /node_modules/,
        use: ["babel-loader"],
      },
      {
        test: /\.s[ac]ss$/i,
        use: [
          MiniCssExtractPlugin.loader,
          // Translates CSS into CommonJS
          "css-loader",
          // Compiles Sass to CSS
          "sass-loader",
        ],
      },
      {
        test: /\.svg$/i,
        issuer: /\.[jt]sx?$/,
        use: ["@svgr/webpack"],
      },
    ],
  },
  // pass all js files through Babel
  resolve: {
    extensions: ["*", ".js", ".jsx"],
  },
};
```
