from conans import ConanFile, tools, CMake
from conans.errors import NotFoundException
import os


class GsoapConan(ConanFile):
    name = "gsoap"
    version_major = "2.8"
    version = version_major + ".87"
    description = "The gSOAP toolkit is a C and C++ software development toolkit for SOAP and " \
                  "REST XML Web services and generic C/C++ XML data bindings."
    # topics can get used for searches, GitHub topics, Bintray tags etc. Add here keywords about the library
    topics = ("conan", "gsoap", "logging")
    url = "https://github.com/bincrafters/conan-gsoap"
    homepage = "https://www.genivia.com/"
    author = "Bincrafters <bincrafters@gmail.com>"
    license = "gSOAP-1.3b"  # Indicates license type of the packaged library; please use SPDX Identifiers https://spdx.org/licenses/
    exports = ["LICENSE.md", "FindGSOAP.cmake"]      # Packages the license for the conanfile.py
    exports_sources = ["CMakeLists.txt", "src/*.cmake", "src/*.txt"]
    generators = "cmake"
    short_paths = True
    settings = "os", "arch", "compiler", "build_type"
    options = {"with_openssl": [True, False],
               "with_ipv6": [True, False],
               "with_cookies": [True, False],
               "with_c_locale": [True, False]}
    default_options = "with_openssl=True", "with_ipv6=True", \
                      "with_cookies=True", "with_c_locale=True"
    # Custom attributes for Bincrafters recipe conventions
    _source_subfolder = "source_subfolder"
    _build_subfolder = "build_subfolder"

    def build_requirements(self):
        if self.settings.os == "Windows":
            self.build_requires("winflexbison/2.5.18@bincrafters/stable")
        else:
            self.build_requires("bison/3.3.2@bincrafters/stable")
            self.build_requires("flex_installer/2.6.4@bincrafters/stable")

    def requirements(self):
        if self.options.with_openssl:
            self.requires("OpenSSL/1.1.1c@conan/stable")

    def source(self):
        sha256 = "0d117633cb973dbd46a0bdcdcba74c67485aa9bc62b065e0ca621fdef9425dda"
        try:
            tools.get("https://sourceforge.net/projects/gsoap2/files/{name}-{version_major}/{name}_{version}.zip/download".format(name=self.name, version_major=self.version_major, version=self.version), sha256=sha256)
        except NotFoundException:  # Maybe it has been moved to `oldreleases`
            tools.get("https://sourceforge.net/projects/gsoap2/files/oldreleases/{name}_{version}.zip/download".format(name=self.name, version=self.version), sha256=sha256)
        # Rename to "source_subfolder" is a convention to simplify later steps
        extracted_dir = self.name + "-" + self.version_major
        os.rename(extracted_dir, self._source_subfolder)

    def _configure_cmake(self):
        cmake = CMake(self)
        cmake.definitions["GSOAP_PATH"] = self._source_subfolder
        
        if self.options.with_openssl:
            cmake.definitions["WITH_OPENSSL"] = True
            cmake.definitions["WITH_GZIP"] = True
        if self.options.with_ipv6:
            cmake.definitions["WITH_IPV6"] = True
        cmake.definitions["WITH_COOKIES"] = self.options.with_cookies
        cmake.definitions["WITH_C_LOCALE"] = self.options.with_c_locale

        cmake.configure(build_folder=self._build_subfolder)
        return cmake

    def build(self):
        cmake = self._configure_cmake()
        cmake.build()
        cmake.install()

    def package(self):
        self.copy(pattern="LICENSE", dst="licenses", src=self._source_subfolder)
        self.copy("FindGSOAP.cmake", dst=".", src=".")
        # If the CMakeLists.txt has a proper install method, the steps below may be redundant
        # If so, you can just remove the lines below
        include_folder = os.path.join(self._source_subfolder, "include")
        self.copy(pattern="*", dst="include", src=include_folder)
        self.copy(pattern="*.dll", dst="bin", keep_path=False)
        self.copy(pattern="*.lib", dst="lib", keep_path=False)
        self.copy(pattern="*.a", dst="lib", keep_path=False)
        self.copy(pattern="*.so*", dst="lib", keep_path=False)
        self.copy(pattern="*.dylib", dst="lib", keep_path=False)

    def package_info(self):
        self.env_info.PATH.append(os.path.join(self.package_folder, "bin"))
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
