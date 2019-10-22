from conans import CMake
from conanfile_base import ConanFileBase
import os


class ConanFileDefault(ConanFileBase):
    name = ConanFileBase._base_name
    version = ConanFileBase.version
    settings = "os", "arch", "compiler", "build_type"
    options = {"with_openssl": [True, False],
               "with_ipv6": [True, False],
               "with_cookies": [True, False],
               "with_c_locale": [True, False]}
    default_options = {
        'with_openssl': True,
        'with_ipv6': True,
        'with_cookies': True,
        'with_c_locale': True}

    def requirements(self):
        if self.options.with_openssl:
            self.requires("openssl/1.1.1d")

    def _configure_cmake(self):
        cmake = CMake(self)
        cmake.definitions["GSOAP_PATH"] = self._source_subfolder
        cmake.definitions["BUILD_TOOLS"] = False
        cmake.definitions["WITH_OPENSSL"] = self.options.with_openssl
        cmake.definitions["WITH_IPV6"] = self.options.with_ipv6
        cmake.definitions["WITH_COOKIES"] = self.options.with_cookies
        cmake.definitions["WITH_C_LOCALE"] = self.options.with_c_locale
        cmake.configure(build_folder=self._build_subfolder)
        return cmake

    def package_info(self):
        defines = []
        if self.options.with_openssl:
            libs = ["gsoapssl++", ]
            defines.append("WITH_OPENSSL")
            defines.append("WITH_GZIP")
        else:
            libs = ["gsoap++", ]
        self.cpp_info.libs = libs

        if self.options.with_ipv6:
            defines.append("WITH_IPV6")
        if self.options.with_cookies:
            defines.append("WITH_COOKIES")
        if self.options.with_c_locale:
            defines.append("WITH_C_LOCALE")
        self.cpp_info.defines = defines
