import os
from conans import ConanFile, CMake

class TestGsoapConan(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "cmake"

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def test(self):
        bin_path = os.path.join("bin", "gsoap_example")
        self.run(bin_path, run_environment=True)
