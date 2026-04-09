pipeline {
    agent any

    stages {
        stage('Check Tools') {
            steps {
                // This will tell us if Jenkins can actually "see" your tools
                bat 'cmake --version'
            }
        }

        stage('Build') {
            steps {
                // 'if not exist' is the safe way to handle directories in Windows bat
                bat """
                    if not exist build mkdir build
                    cd build
                    cmake ..
                    cmake --build . --config Release
                """
            }
        }

        stage('Test') {
            steps {
                bat """
                    cd build
                    ctest --output-on-failure
                """
            }
        }

        stage('Archive') {
            steps {
                // Note: Windows builds often put the .exe in a 'Release' or 'Debug' folder
                archiveArtifacts artifacts: 'build/**/*.exe', fingerprint: true
            }
        }
    }
}
