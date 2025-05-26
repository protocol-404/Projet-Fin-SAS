# GitHub Actions Workflows

This directory contains GitHub Actions workflows for the Dental Appointment Reservation System.

## Workflows

### 1. CI/CD Pipeline (`ci.yml`)
**Triggers:** Push to main/develop, Pull Requests to main, Releases

**Features:**
- **Multi-platform builds** (Ubuntu Latest, Ubuntu 20.04)
- **Multi-compiler support** (GCC, Clang)
- **Comprehensive testing suite**
- **Code quality analysis**
- **Security scanning**
- **Memory safety testing with Valgrind**
- **Automatic release packaging**
- **Documentation generation**

### 2. Pull Request Check (`pr-check.yml`)
**Triggers:** Pull Requests to main/develop

**Features:**
- Quick build verification
- Basic functionality tests
- Code style checks
- Fast feedback for contributors

### 3. Release Build (`release.yml`)
**Triggers:** Git tags (v*), Published releases

**Features:**
- Optimized release builds
- Multi-platform binaries
- Automated release asset uploads
- Release packaging with documentation

### 4. Development Build (`dev.yml`)
**Triggers:** Push to main/develop, Manual dispatch

**Features:**
- Continuous integration for development
- Comprehensive test suite execution
- Performance testing
- Build artifact retention
- Detailed system information logging

## Workflow Status Badges

Add these badges to your main README.md:

```markdown
![CI/CD Pipeline](https://github.com/yourusername/Projet-Fin-SAS/workflows/CI%2FCD%20Pipeline/badge.svg)
![Development Build](https://github.com/yourusername/Projet-Fin-SAS/workflows/Development%20Build/badge.svg)
![Release Build](https://github.com/yourusername/Projet-Fin-SAS/workflows/Release%20Build/badge.svg)
```

## Setting Up

1. **Push to GitHub**: Commit these workflow files to your repository
2. **Enable Actions**: Go to the "Actions" tab in your GitHub repository
3. **Configure Secrets**: If needed, add repository secrets for deployment
4. **Enable Pages**: For documentation deployment, enable GitHub Pages in repository settings

## Workflow Features

### Build Matrix
- **Operating Systems**: Ubuntu Latest, Ubuntu 20.04
- **Compilers**: GCC, Clang
- **Build Types**: Debug, Release, Optimized

### Testing Levels
1. **Unit Tests**: Individual component testing
2. **Integration Tests**: Complete workflow testing
3. **Validation Tests**: Input validation and error handling
4. **Performance Tests**: Timing and efficiency measurements
5. **Memory Tests**: Valgrind memory leak detection

### Code Quality
- **Static Analysis**: Cppcheck for potential issues
- **Security Scan**: Detection of unsafe C functions
- **Style Check**: Basic formatting consistency
- **Compiler Warnings**: Strict warning levels

### Artifacts
- **Build Binaries**: Compiled executables for each platform
- **Release Packages**: Compressed releases with documentation
- **Test Reports**: Results from all test suites
- **Documentation**: Generated API documentation

## Manual Workflow Triggers

You can manually trigger workflows from the GitHub Actions tab:

1. Go to **Actions** tab in your repository
2. Select the workflow you want to run
3. Click **Run workflow** button
4. Choose the branch and click **Run workflow**

## Customization

### Adding New Tests
Add new test scripts to the repository and include them in the workflow YAML files:

```yaml
- name: Run custom test
  run: |
    chmod +x your_test_script.sh
    ./your_test_script.sh
```

### Platform Support
To add more platforms, update the matrix strategy:

```yaml
strategy:
  matrix:
    os: [ubuntu-latest, ubuntu-20.04, ubuntu-18.04]
    compiler: [gcc, clang, gcc-9]
```

### Environment Variables
Add environment variables for different configurations:

```yaml
env:
  BUILD_TYPE: Release
  OPTIMIZATION_LEVEL: O2
```

## Troubleshooting

### Common Issues

1. **Test Failures**: Check the test logs in the Actions tab
2. **Build Errors**: Verify dependencies and compiler versions
3. **Permission Issues**: Ensure test scripts have execute permissions
4. **Artifact Upload**: Check file paths and artifact retention settings

### Debugging Workflows

1. Add debug steps to workflows:
```yaml
- name: Debug information
  run: |
    pwd
    ls -la
    env
```

2. Use workflow dispatch for manual testing
3. Check the Actions tab for detailed logs
4. Use the re-run option for transient failures

## Security Considerations

- Workflows run in isolated environments
- No sensitive data should be logged
- Use GitHub secrets for sensitive configuration
- Review third-party actions before use

## Performance Optimization

- Use caching for dependencies when possible
- Parallel job execution for independent tasks
- Conditional workflow execution
- Appropriate artifact retention periods
