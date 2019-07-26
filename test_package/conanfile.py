import os

from conans import ConanFile, CMake, tools, RunEnvironment


class TestGsoapConan(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "cmake"

    def build(self):
        with tools.environment_append(RunEnvironment(self).vars):
            calc_wsdl = os.path.join(os.path.dirname(__file__), 'calc.wsdl')
            self.run("wsdl2h -o calc.h {}".format(calc_wsdl))
            self.run("soapcpp2 -j -CL -I{} calc.h".format(os.path.join(self.deps_cpp_info["gsoap"].rootpath, 'import')))

        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def imports(self):
        self.copy("*.dll", dst="bin", src="bin")
        self.copy("*.dylib*", dst="bin", src="lib")
        self.copy('*.so*', dst='bin', src='lib')

    def test(self):
        if not tools.cross_building(self.settings):
            bin_path = os.path.join("bin", "gsoap_example")
            self.run(bin_path, run_environment=True)