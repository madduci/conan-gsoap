from conans import CMake
from conanfile_base import ConanFileBase
import os


class ConanFileInstaller(ConanFileBase):
    name = ConanFileBase._base_name + "_installer"
    version = ConanFileBase.version
    settings = "os_build", "arch_build", "compiler"

    def build_requirements(self):
        if self.settings.os_build == "Windows":
            self.build_requires("winflexbison/2.5.22")
        else:
            self.build_requires("bison/3.5.3")
            self.build_requires("flex/2.6.4")

    def requirements(self):
        self.requires("openssl/1.1.1g")

    def _configure_cmake(self):
        cmake = CMake(self)
        cmake.definitions["GSOAP_PATH"] = self._source_subfolder
        cmake.definitions["BUILD_GSOAP"] = False
        cmake.definitions["BUILD_TOOLS"] = True
        cmake.configure(build_folder=self._build_subfolder)
        return cmake

    def package_id(self):
        del self.info.settings.compiler

    def package_info(self):
        bin_path = os.path.join(self.package_folder, "bin")
        self.output.info("Appending PATH environment variable: {}".format(bin_path))
        self.env_info.PATH.append(bin_path)
