# Dependency Maintenance Notes

This repository contains older JavaScript, React, and React Native study projects.
GitHub Dependabot may report many vulnerabilities from their dependency manifests
and lockfiles.

## What Was Cleaned Up

- Installed dependency directories are no longer tracked by Git.
- The root `.gitignore` excludes `node_modules/`, `.venv/`, `.pytest_cache/`, and Python cache files.
- `JavaScript/JS/package-lock.json` was refreshed with `npm audit fix --package-lock-only`.
  This project only depends on `underscore`, and the lockfile now resolves it to a non-vulnerable compatible version.

## Why Not Use `npm audit fix --force` Everywhere?

Several projects are based on old framework versions:

- `react-scripts@3.0.1`
- `react-native@0.60.x`
- `jest@24.x`
- old Expo SDK 33 React Native dependencies

For these projects, `npm audit fix --force` would upgrade core tooling such as
`react-scripts`, `react-native`, `jest`, `eslint`, or Metro to much newer major
versions. Those upgrades are breaking changes and should be handled project by
project with runtime verification.

## Projects Requiring Project-Level Upgrade Work

The following project groups still need dedicated upgrade passes:

- `JavaScript/Jest`
- `JavaScript/hello-react`
- `JavaScript/test`
- `React/my-app`
- `React/phone-book`
- `React/tic-tac-toe/tic-tac-toe`
- `React/todo`
- `React`
- `ReactNative/AwesomeProject`
- `ReactNative/FeeLStagram`
- `ReactNative/FeeLWebViewTest`
- `ReactNative/FirstProject`
- `ReactNative/FunckingWeather`
- `ReactNative/TestProject`
- `ReactNative/TestWebView`
- `ReactNative/test`

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
