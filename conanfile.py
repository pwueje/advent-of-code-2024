from conan import ConanFile
from conan.tools.cmake import cmake_layout

class MatrixConanFile(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeToolchain", "CMakeDeps"
    
    def requirements(self):
        self.requires("argparse/3.1")

    def build_requirements(self):
        self.test_requires("catch2/3.7.1")
        
    def layout(self):
        cmake_layout(self)