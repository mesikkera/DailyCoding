# Dependency Maintenance Notes

This repository contains older JavaScript, React, and React Native study projects.
GitHub Dependabot may report many vulnerabilities from their dependency manifests
and lockfiles.

## What Was Cleaned Up

- Installed dependency directories are no longer tracked by Git.
- The root `.gitignore` excludes `node_modules/`, `.venv/`, `.pytest_cache/`, and Python cache files.
- `JavaScript/JS/package-lock.json` was refreshed with `npm audit fix --package-lock-only`.
  This project only depends on `underscore`, and the lockfile now resolves it to a non-vulnerable compatible version.
- `JavaScript/Jest` was moved from an old Yarn lockfile and `jest@24.x` to npm
  with `jest@30.x`. Its test suite and `npm audit --audit-level=low` now pass.
- Older Create React App projects were migrated away from `react-scripts@3.x`
  to React 18, Vite, and Vitest:
  - `JavaScript/hello-react`
  - `JavaScript/test`
  - `React/my-app`
  - `React/phone-book`
  - `React/tic-tac-toe/tic-tac-toe`
  - `React/todo`
- The root `React` package was refreshed to a current React/Redux dependency set.
- Stale `yarn.lock` files were removed from projects that now use npm
  `package-lock.json`, so GitHub Dependabot does not scan duplicate old
  dependency graphs.

## Why Not Use `npm audit fix --force` Everywhere?

Several projects were or still are based on old framework versions:

- `react-native@0.60.x`
- old Expo SDK 33 React Native dependencies

For these projects, `npm audit fix --force` would upgrade core tooling such as
`react-native`, Expo, `eslint`, or Metro to much newer major versions. Those
upgrades are breaking changes and should be handled project by project with
runtime verification on the native targets.

## Projects Requiring Project-Level Upgrade Work

The following project groups have already been upgraded and verified with tests,
builds where applicable, and `npm audit --audit-level=low`:

- `JavaScript/Jest`
- `JavaScript/hello-react`
- `JavaScript/test`
- `React/my-app`
- `React/phone-book`
- `React/tic-tac-toe/tic-tac-toe`
- `React/todo`
- `React`

The following React Native and Expo project groups still need dedicated native
migration passes:

- `ReactNative/AwesomeProject`
- `ReactNative/FeeLStagram`
- `ReactNative/FeeLWebViewTest`
- `ReactNative/FirstProject`
- `ReactNative/FunckingWeather`
- `ReactNative/TestProject`
- `ReactNative/TestWebView`
- `ReactNative/test`

Current npm-auditable React Native / Expo projects still report vulnerabilities
because their direct framework dependencies are old:

- `ReactNative/FeeLStagram`: `react-native@0.60.4`, `native-base@2.x`,
  `react-native-webview@5.x`
- `ReactNative/FeeLWebViewTest`: `react-native@0.60.4`
- `ReactNative/FunckingWeather`: Expo SDK 33
- `ReactNative/TestWebView`: `react-native@0.60.4`
- `ReactNative/test`: `react-native@0.60.3`

These should not be fixed with a blind package-only bump. A safe fix requires
running the React Native or Expo upgrade path, updating native iOS/Android
project files, reinstalling pods where relevant, and smoke testing on a target
simulator or device.

## Recommended Cleanup Strategy

For each project, handle upgrades separately:

1. Choose one package manager per project.
2. Remove duplicate lockfiles when both `package-lock.json` and `yarn.lock` exist.
3. Upgrade the framework or toolchain intentionally.
4. Reinstall dependencies from a clean state.
5. Run the project's tests or start command.
6. Commit the project-specific upgrade separately.

This keeps dependency maintenance understandable and avoids mixing unrelated
framework migrations into one large security cleanup commit.
