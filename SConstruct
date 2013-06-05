# @COPYRIGHT@
# 
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
# 
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
# 
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE

import os

def BuildVariant(env, variant_dir, src_dir, duplicate = 0, **kw):
    SConscript( '%s/SConscript' % variant_dir, exports = ['env'] )

EnsureSConsVersion(2,2)
env = Environment(tools =  [ 'default'
                           , 'textfile'
                           , 'gettext'
                           , 'doxygen'
                           , 'protoc'
                           , 'swig' ],
                  ENV = os.environ )

# Variant directories
variants = [
  { 'variant_dir' : 'build', 
    'src_dir' : 'src', 
    'duplicate' : 0,
    'env' : env.Clone() }
]

# Prepare variants
for v in variants:
    kw = { k: v[k] for k in v if k in ('variant_dir', 'src_dir', 'duplicate')}
    VariantDir(**kw)
# Build variants
for v in variants:
    BuildVariant(**v)
    

# Builds independent on variants.
SConscript( 'src/SConscript.i18n', exports = ['env'] )

# Global targets
api_doc = env.AlwaysBuild(env.Alias('api-doc'))
env.Depends(api_doc, env.Glob('bin/doxy*'))

# Local Variables:
# # tab-width:4
# # indent-tabs-mode:nil
# # End:
# vim: set syntax=scons expandtab tabstop=4 shiftwidth=4:
