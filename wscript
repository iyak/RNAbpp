def options(opt):
	opt.load('compiler_cxx waf_unit_test')

def configure(cgf):
	cgf.load('compiler_cxx waf_unit_test')

def build(bld):
	assemble_executable(bld)

def assemble_executable(bld):
	bld.program(
		cxxflags='-std=c++11',
		source='RNAbpp/main.cpp', 
		target='bpp',
		includes='RNAbpp')
