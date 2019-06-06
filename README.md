# Non-deterministic Turing machine simulator

Implementation in C99, using only the standard library (libc) and the base runtime, of a non-deterministic Turing machine, in the single tape variant, that accepts or rejects strings based on a given set of transitions.

## Usage

Build:
```sh
$ ./build.sh
```

Different run methods:
```sh
$ ./build/src/project
$ ./build/src/project < test/cases/file.input
$ ./build/src/project < test/cases/file.input | diff test/cases/file.output -
```

Run all test cases:
```sh
$ ./test/test_cases.sh
```

## Authors

* **Federico Capaccio**
