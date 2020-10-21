
unix {
    QMAKE_MKPATH = mkdir -p
} else {
    QMAKE_MKPATH = mkdir
}

defineReplace(qtInfo) {
    message(Qt version: $$[QT_VERSION])
    message(Qt is installed in $$[QT_INSTALL_PREFIX])
    message(Qt resources can be found in the following locations:)
    message(Documentation: $$[QT_INSTALL_DOCS])
    message(Header files: $$[QT_INSTALL_HEADERS])
    message(Libraries: $$[QT_INSTALL_LIBS])
    message(Binary files (executables): $$[QT_INSTALL_BINS])
    message(Plugins: $$[QT_INSTALL_PLUGINS])
    message(Data files: $$[QT_INSTALL_DATA])
    message(Translation files: $$[QT_INSTALL_TRANSLATIONS])
    message(Settings: $$[QT_INSTALL_CONFIGURATION])
    message(Examples: $$[QT_INSTALL_EXAMPLES])
}

# Creates a path if it does not exist
defineReplace(makePath) {
    path = $$system_path($$1)
    test = $$sprintf($$QMAKE_CHK_EXISTS, $$shell_quote($$path))
    retVal = $$test $$QMAKE_MKPATH $$shell_quote($$path) $$escape_expand(\\n\\t)
    return($$retVal)
}

# Returns the path to Qt
defineReplace(getQtPath) {
    return($$[QT_INSTALL_PREFIX])
}

# Returns the path to Qt binaries
defineReplace(getQtBinPath) {
    return($$[QT_INSTALL_BINS])
}

# Returns the path to Qt libraries
defineReplace(getQtLibPath) {
    return($$[QT_INSTALL_LIBS])
}

# Returns the path to Qt plugins
defineReplace(getQtPluginPath) {
    return($$[QT_INSTALL_PLUGINS])
}

# Makes a file executable on Unix-like systems
defineReplace(makeExecutable) {
    # Collect arguments
    files = $$1
    targetDir = $$2
    returnValue = ""

    # Process each input file
    for(file, files) {
        # Compose full target file name
        finalTargetFile = $$targetDir/$$file

        # Invoke chmod command
        cmd = chmod +x $$shell_quote($$system_path($$finalTargetFile)) $$escape_expand(\\n\\t)
        returnValue += $$cmd
    }

    return($$returnValue)
}

# Copies a list of directories with relative paths (all content, recursively) to a target directory
# Arguments: source directory, list of relative directory names, target directory
defineReplace(copyDirsToDir) {
    # Collect arguments
    sourceDir = $$1
    files = $$2
    targetDir = $$3
    returnValue = ""

    # Process each input directory
    for(file, files) {
        # Compose full source file name
        finalSource = $$sourceDir/$$file

        # Compose full target file name
        finalTargetFile = $$targetDir/$$file

        # Compose full target directory name: the file name may contain a relative path
        finalTargetDir = $$targetDir/$$file
        lastItem = $$section(finalTargetDir, /, -1, -1)
        finalTargetDir ~= s,$$lastItem,,g

        # Invoke make path command before copying the directory
        cmd = $$makePath($$finalTargetDir) $$escape_expand(\\n\\t)
        returnValue += $$cmd

        # Invoke copy command
        cmd = $$QMAKE_COPY_DIR $$shell_quote($$system_path($$finalSource)) $$shell_quote($$system_path($$finalTargetFile)) $$escape_expand(\\n\\t)
        returnValue += $$cmd
    }

    return($$returnValue)
}

# Copies a list of files to a target directory
# Arguments: source directory, list of relative file names, target directory
defineReplace(copyFilesToDir) {
    # Collect arguments
    sourceDir = $$1
    files = $$2
    targetDir = $$3
    returnValue = ""

    # Process each input file
    for(file, files) {
        # Compose full source file name
        finalSource = $$sourceDir/$$file
        fileName = $$section(file, /, -1, -1)

        # Compose full target file name
        finalTargetFile = $$targetDir/$$fileName

        # Invoke make path command before copying the file
        cmd = $$makePath($$targetDir) $$escape_expand(\\n\\t)
        returnValue += $$cmd

        # Invoke copy command
        cmd = $$QMAKE_COPY $$shell_quote($$system_path($$finalSource)) $$shell_quote($$system_path($$finalTargetFile)) $$escape_expand(\\n\\t)
        returnValue += $$cmd
    }

    return($$returnValue)
}

# Copies a list of files with relative paths to a target directory
# Unlike copyFilesToDir, the relative path of files is added to the target path
# Arguments: source directory, list of relative file names, target directory
defineReplace(copyFilesWithPathToDir) {
    # Collect arguments
    sourceDir = $$1
    files = $$2
    targetDir = $$3
    returnValue = ""

    # Process each input file
    for(file, files) {
        # Compose full source file name
        finalSource = $$sourceDir/$$file

        # Compose full target file name
        finalTargetFile = $$targetDir/$$file

        # Compose full target directory name: the file name may contain a relative path
        finalTargetDir = $$targetDir/$$file
        lastItem = $$section(finalTargetDir, /, -1, -1)
        finalTargetDir ~= s,$$lastItem,,g

        # Invoke make path command before copying the file
        cmd = $$makePath($$shell_quote($$finalTargetDir)) $$escape_expand(\\n\\t)
        returnValue += $$cmd

        # Invoke copy command
        cmd = $$QMAKE_COPY $$shell_quote($$system_path($$finalSource)) $$shell_quote($$system_path($$finalTargetFile)) $$escape_expand(\\n\\t)
        returnValue += $$cmd
    }

    return($$returnValue)
}
