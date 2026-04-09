pipeline {
    agent any

    stages {
        stage('Initialize') {
            steps {
                // Creates the build directory if it doesn't exist
                sh 'mkdir -p build'
            }
        }

        stage('Build') {
            steps {
                dir('build') {
                    // 1. Run CMake pointing to the root CMakeLists.txt
                    // 2. Compile the project
                    sh 'cmake ..'
                    sh 'make'
                }
            }
        }

        stage('Test') {
            steps {
                dir('build') {
                    // Runs the tests defined in tests/CMakeLists.txt
                    // and registered via add_test
                    sh 'ctest --output-on-failure'
                }
            }
        }

        stage('Deploy/Archive') {
            steps {
                // Archives the resulting binary from the build folder
                archiveArtifacts artifacts: 'build/MyProject', fingerprint: true
            }
        }
    }

    post {
        always {
            echo 'Cleaning up workspace...'
            // Optional: cleans up build artifacts after the run
        }
        failure {
            echo 'Build or Tests failed. Please check the console output.'
        }
    }
}
