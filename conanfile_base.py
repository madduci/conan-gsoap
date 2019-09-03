from conans import ConanFile, tools
from conans.errors import NotFoundException
import os


class ConanFileBase(ConanFile):
    _base_name = "gsoap"
    version_major = "2.8"
    version = version_major + ".91"
    description = "The gSOAP toolkit is a C and C++ software development toolkit for SOAP and " \
                  "REST XML Web services and generic C/C++ XML data bindings."
    topics = ("conan", "gsoap", "logging")
    url = "https://github.com/bincrafters/conan-gsoap"
    homepage = "https://www.genivia.com"
    author = "Bincrafters <bincrafters@gmail.com>"
    license = "gSOAP-1.3b"
    exports = ["LICENSE.md", "conanfile_base.py"]
    exports_sources = ["CMakeLists.txt", "src/*.cmake", "src/*.txt"]
    generators = "cmake"
    short_paths = True

    @property
    def _source_subfolder(self):
        return "source_subfolder"

    @property
    def _build_subfolder(self):
        return "build_subfolder"

    def source(self):
        sha256 = "2ca21b5ab2b40d899566c559f71a1d51ed7eac3f00160ab78060027a3ee6488f"
        try:
            tools.get("https://sourceforge.net/projects/gsoap2/files/{name}-{version_major}/{name}_{version}.zip/download".format(name=self._base_name, version_major=self.version_major, version=self.version), sha256=sha256)
        except NotFoundException:  # Maybe it has been moved to `oldreleases`
            tools.get("https://sourceforge.net/projects/gsoap2/files/oldreleases/{name}_{version}.zip/download".format(name=self._base_name, version=self.version), sha256=sha256)
        # Rename to "source_subfolder" is a convention to simplify later steps
        extracted_dir = self._base_name + "-" + self.version_major
        os.rename(extracted_dir, self._source_subfolder)

    def build(self):
        cmake = self._configure_cmake()
        cmake.build()

    def package(self):
        self.copy(pattern="GPLv2_license.txt", dst="licenses", src=self._source_subfolder)
        self.copy(pattern="LICENSE.txt", dst="licenses", src=self._source_subfolder)
        cmake = self._configure_cmake()
        cmake.install()
