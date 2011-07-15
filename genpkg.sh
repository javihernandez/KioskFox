#!/bin/bash
# This is just an easy way for generating a new .xpi file

zip kioskfox.xpi -r chrome* components/ defaults/ install.rdf README.rdoc resources/ source/
