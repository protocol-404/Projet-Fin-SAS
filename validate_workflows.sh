#!/bin/bash

# GitHub Actions Workflow Validation Script
# This script validates the YAML syntax of GitHub Actions workflows

echo "🔍 Validating GitHub Actions Workflows..."
echo "========================================"

# Check if yamllint is available
if ! command -v yamllint &> /dev/null; then
    echo "⚠️  yamllint not found. Installing..."
    # Try to install yamllint
    if command -v pip3 &> /dev/null; then
        pip3 install --user yamllint
    elif command -v apt-get &> /dev/null; then
        sudo apt-get update && sudo apt-get install -y yamllint
    else
        echo "❌ Cannot install yamllint. Please install it manually."
        echo "   pip3 install yamllint"
        echo ""
        echo "🔧 Performing basic validation instead..."
        BASIC_CHECK=true
    fi
fi

# Function to perform basic YAML validation
basic_yaml_check() {
    local file="$1"
    local filename=$(basename "$file")
    
    echo "🔍 Checking $filename..."
    
    # Check for basic YAML structure
    if grep -q "^name:" "$file" && grep -q "^on:" "$file" && grep -q "^jobs:" "$file"; then
        echo "  ✅ Basic structure: OK"
    else
        echo "  ❌ Basic structure: Missing required sections"
        return 1
    fi
    
    # Check for proper indentation (basic check)
    if grep -q "^    " "$file"; then
        echo "  ✅ Indentation: Found proper spacing"
    else
        echo "  ⚠️  Indentation: May have issues"
    fi
    
    # Check for GitHub Actions syntax
    if grep -q "uses: actions/" "$file"; then
        echo "  ✅ GitHub Actions: Found action references"
    else
        echo "  ⚠️  GitHub Actions: No action references found"
    fi
    
    echo "  ✅ $filename appears to be valid"
    echo ""
    return 0
}

# Function to perform yamllint validation
yamllint_check() {
    local file="$1"
    local filename=$(basename "$file")
    
    echo "🔍 Checking $filename with yamllint..."
    
    if yamllint "$file"; then
        echo "  ✅ $filename: YAML syntax is valid"
    else
        echo "  ❌ $filename: YAML syntax errors found"
        return 1
    fi
    echo ""
    return 0
}

# Main validation
cd "$(dirname "$0")"
WORKFLOW_DIR=".github/workflows"
ERRORS=0

if [ ! -d "$WORKFLOW_DIR" ]; then
    echo "❌ No .github/workflows directory found!"
    exit 1
fi

echo "📁 Found workflow directory: $WORKFLOW_DIR"
echo ""

# Validate each workflow file
for workflow in "$WORKFLOW_DIR"/*.yml; do
    if [ -f "$workflow" ]; then
        if [ "$BASIC_CHECK" = "true" ]; then
            basic_yaml_check "$workflow" || ((ERRORS++))
        else
            yamllint_check "$workflow" || ((ERRORS++))
        fi
    fi
done

# Summary
echo "========================================"
if [ $ERRORS -eq 0 ]; then
    echo "🎉 All workflows validated successfully!"
    echo ""
    echo "📋 Summary of created workflows:"
    echo "  • ci.yml         - Complete CI/CD pipeline"
    echo "  • dev.yml        - Development builds"
    echo "  • pr-check.yml   - Pull request validation"
    echo "  • release.yml    - Release automation"
    echo ""
    echo "🚀 Ready to push to GitHub!"
else
    echo "❌ Found $ERRORS error(s) in workflow files"
    echo "   Please fix the issues before pushing to GitHub"
    exit 1
fi

# Show next steps
echo "📝 Next Steps:"
echo "1. Commit the .github directory:"
echo "   git add .github/"
echo "   git commit -m \"Add GitHub Actions workflows and templates\""
echo ""
echo "2. Push to GitHub:"
echo "   git push origin main"
echo ""
echo "3. Check the Actions tab in your GitHub repository"
echo "4. Create a release to test the release workflow"
echo ""
echo "📖 For more information, see: .github/workflows/README.md"
