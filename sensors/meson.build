    project('sensors',
        [ 'c', 'cpp' ],
        license: [ 'GPLv2' ],
        default_options: [ 'c_std=c11', 'cpp_std=c++2a', 'b_asneeded=false', 'b_lundef=false'],
        version: '1.0.0'
    )

c_args = [ '-DBOARD=ASGARD', '-DYGGDRASIL_PERIPHERAL_DEFS' ]
cpp_args = [ ] + c_args

# Make sure the project gets cross compiled
    assert(meson.is_cross_build(), 'This project can only be cross-compiled. Make sure to call meson with the "--cross-file=asgard" option!')


# Available portlib libraries 
    sysroot = meson.get_cross_property('sys_root')

    libstdcpp = declare_dependency(link_args : [ '-L' + sysroot + '/lib/libc.a', '-static-libstdc++', '-static-libgcc' ])

    linux_headers = sysroot + '/usr/include'

    libyggdrasil = subproject('libyggdrasil').get_variable('dep')



# Source files and include directories
    source_files = [
        'source/main.cpp',
    ]

    include_dirs = include_directories('include', linux_headers)


# Executable building
    application = executable(
        'sensors.elf',
        source_files,
        native: false,
        c_args: c_args,
        cpp_args: cpp_args,
        name_prefix: '',
        dependencies: [ libstdcpp, libyggdrasil ],
        include_directories: include_dirs
    )