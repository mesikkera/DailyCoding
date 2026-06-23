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
- Obsolete React Native study projects were removed from the repository. Their
  historical contents remain available from Git history if needed.

## Why Not Use `npm audit fix --force` Everywhere?

Several old projects were based on framework versions that require major
migration rather than blind `npm audit fix --force`, such as
`react-scripts@3.x`, `jest@24.x`, `react-native@0.60.x`, and Expo SDK 33.
The web projects were migrated to current npm dependency graphs. The old React
Native study projects were removed instead of migrated.

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

If a deleted React Native example is needed again, restore it from Git history
and migrate it as a fresh native project instead of reintroducing the old
dependency graph unchanged.

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
