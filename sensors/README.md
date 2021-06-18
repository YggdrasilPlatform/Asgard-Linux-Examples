# Asgard Template for Linux

## Usage

### Environment setup
To build this project, download the latest version of the yggdrasil toolchain and install it to the `/opt` directory.

### Configuring
Run this command once at the start to setup the project.
```
$ meson build --cross-file=asgard
```

### Compiling
Run this command for compiling the project.
```
$ meson compile -C build
```

