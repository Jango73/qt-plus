
unix {
    QMAKE_MKPATH = mkdir -p
} else {
    QMAKE_MKPATH = mkdir
}

defineReplace(makePath) {
    path = $$shell_quote($$system_path($$1))
    test = $$sprintf($$QMAKE_CHK_EXISTS, $$path)
    retVal = $$test $$QMAKE_MKPATH $$path $$escape_expand(\\n\\t)
    return($$retVal)
}

defineReplace(getQtPath) {
    TEMP_NAME = $${QMAKE_QMAKE}
    QT_PATH = $$dirname(TEMP_NAME)
    QT_BASE_PATH = $$absolute_path($${QT_PATH}/..)

    return($$QT_BASE_PATH)
}

defineReplace(getQtBinPath) {
    TEMP_NAME = $${QMAKE_QMAKE}
    QT_BIN_PATH = $$dirname(TEMP_NAME)

    return($$QT_BIN_PATH)
}

defineReplace(getQtLibPath) {
    unix {
        return($$getQtPath()/lib)
    } else {
        return($$getQtPath()/bin)
    }
}

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

        # Compose full target directory name
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

        # Invoke copy command
        cmd = $$QMAKE_COPY $$shell_quote($$system_path($$finalSource)) $$shell_quote($$system_path($$finalTargetFile)) $$escape_expand(\\n\\t)
        returnValue += $$cmd
    }

    return($$returnValue)
}

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

        # Compose full target directory name
        finalTargetDir = $$targetDir/$$file
        lastItem = $$section(finalTargetDir, /, -1, -1)
        finalTargetDir ~= s,$$lastItem,,g

        # Invoke make path command before copying the file
        cmd = $$makePath($$finalTargetDir) $$escape_expand(\\n\\t)
        returnValue += $$cmd

        # Invoke copy command
        cmd = $$QMAKE_COPY $$shell_quote($$system_path($$finalSource)) $$shell_quote($$system_path($$finalTargetFile)) $$escape_expand(\\n\\t)
        returnValue += $$cmd
    }

    return($$returnValue)
}
