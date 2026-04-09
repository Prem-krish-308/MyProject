pipeline {
    agent any

    environment {
        // Defines the name of the final binary based on your CMake setup
        APP_NAME = "MyProject"
        BUILD_DIR = "build"
    }

    stages {
        stage('Checkout') {
            steps {
                checkout scm
            }
        }

        stage('Prepare') {
            steps {
                // Ensure the build directory exists (it is ignored by git)
                bat "mkdir -p ${BUILD_DIR}"
            }
        }

        stage('Build') {
            steps {
                dir("${BUILD_DIR}") {
                    bat 'cmake ..'
                    bat 'make'
                }
            }
        }

        stage('Unit Test') {
            steps {
                dir("${BUILD_DIR}") {
                    // Executes the tests found in the tests/ directory
                    bat 'ctest --output-on-failure'
                }
            }
        }

        stage('Archive Artifacts') {
            steps {
                // This "creates an artifactory" inside Jenkins for this build.
                // It saves the compiled binary so it can be downloaded later.
                archiveArtifacts artifacts: "${BUILD_DIR}/${APP_NAME}", fingerprint: true
            }
        }
    }

    post {
        success {
            echo "Successfully built and archived ${APP_NAME}."
        }
        failure {
            echo "Build failed. Check the console output for CMake or GTest errors."
        }
    }
}
