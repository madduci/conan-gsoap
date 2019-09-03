import os
from conans import ConanFile


class TestGsoapConan(ConanFile):

    def test(self):
        calc_wsdl = os.path.join(os.path.dirname(__file__), 'calc.wsdl')
        self.run("wsdl2h -o calc.h {}".format(calc_wsdl), run_environment=True)
        self.run("soapcpp2 -j -CL -I{} calc.h".format(os.path.join(self.deps_cpp_info["gsoap_installer"].rootpath, 'import')), run_environment=True)