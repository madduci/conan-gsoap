from conans import ConanFile, tools, CMake
from conans.errors import NotFoundException
import os


class GsoapConan(ConanFile):
    name = "gsoap"
    version_major = "2.8"
    version = version_major + ".91"
    description = "The gSOAP toolkit is a C and C++ software development toolkit for SOAP and " \
                  "REST XML Web services and generic C/C++ XML data bindings."
    topics = ("conan", "gsoap", "logging")
    url = "https://github.com/bincrafters/conan-gsoap"
    homepage = "https://www.genivia.com"
    author = "Bincrafters <bincrafters@gmail.com>"
    license = "gSOAP-1.3b"
    exports = ["LICENSE.md"]
    exports_sources = ["CMakeLists.txt", "src/*.cmake", "src/*.txt"]
    generators = "cmake"
    short_paths = True
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

    @property
    def _source_subfolder(self):
        return "source_subfolder"

    @property
    def _build_subfolder(self):
        return "build_subfolder"

    def build_requirements(self):
        if self.settings.os == "Windows":
            self.build_requires("winflexbison/2.5.18@bincrafters/stable")
        else:
            self.build_requires("bison_installer/3.3.2@bincrafters/stable")
            self.build_requires("flex_installer/2.6.4@bincrafters/stable")

    def requirements(self):
        if self.options.with_openssl:
            self.requires("OpenSSL/1.1.1c@conan/stable")

    def source(self):
        sha256 = "2ca21b5ab2b40d899566c559f71a1d51ed7eac3f00160ab78060027a3ee6488f"
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
        cmake.definitions["WITH_OPENSSL"] = self.options.with_openssl
        cmake.definitions["WITH_IPV6"] = self.options.with_ipv6
        cmake.definitions["WITH_COOKIES"] = self.options.with_cookies
        cmake.definitions["WITH_C_LOCALE"] = self.options.with_c_locale
        cmake.configure(build_folder=self._build_subfolder)
        return cmake

    def build(self):
        cmake = self._configure_cmake()
        cmake.build()

    def package(self):
        self.copy(pattern="GPLv2_license.txt", dst="licenses", src=self._source_subfolder)
        self.copy(pattern="LICENSE.txt", dst="licenses", src=self._source_subfolder)
        cmake = self._configure_cmake()
        cmake.install()

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
