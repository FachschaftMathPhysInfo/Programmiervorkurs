#!/bin/bash
set -e

echo "=== LaTeX Auto-Formatter ==="

if ! command -v latexindent &>/dev/null; then
  echo "latexindent.pl not found. Please install TeX Live or MacTeX."
  exit 1
fi

missing_modules=()
for module in YAML::Tiny File::HomeDir Unicode::GCString File::Find::Rule; do
  perl -M$module -e1 2>/dev/null || missing_modules+=($module)
done

if [ ${#missing_modules[@]} -ne 0 ]; then
  echo "The following Perl modules are missing:"
  for module in "${missing_modules[@]}"; do
    echo "  - $module"
  done
  echo ""
  echo "Options:"
  echo "  [i] Install missing modules automatically (requires cpan, may need sudo)"
  echo "  [s] Skip installation and try formatting anyway"
  echo "  [a] Abort"
  read -p "What do you want to do? [i/s/a]: " choice
  case "$choice" in
  i | I)
    for module in "${missing_modules[@]}"; do
      echo "Installing $module with cpan..."
      if ! cpan -i $module; then
        echo "Permission denied or install failed. Retrying with sudo..."
        sudo cpan -i $module
      fi
    done
    ;;
  s | S)
    echo "Skipping installation. Formatting may fail."
    ;;
  *)
    echo "Aborted."
    exit 1
    ;;
  esac
else
  echo "All required Perl modules are installed."
fi

echo "Formatting all .tex files..."
find . -name "*.tex" -exec latexindent -w {} \;
echo "Done! All LaTeX files have been formatted."

echo "Cleaning up backup files..."
find . -type f -name "*.bak*" -exec rm -v {} \;
echo "Cleanup complete."
