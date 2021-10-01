#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import sys
import os
sys.path.append(os.path.abspath("../"))
from conf import *
extensions.append('sphinx_gitstamp')
extensions.append('sphinx_copybutton')
extensions.append('sphinx_togglebutton')
html_theme = 'sphinx_material'
html_sidebars['**']=['globaltoc.html', 'searchbox.html', 'localtoc.html', 'logo-text.html']
html_theme_options = {
    'base_url': 'http://bashtage.github.io/sphinx-material/',
    'repo_url': 'https://github.com/percona/percona-xtrabackup',
    'repo_name': 'percona/percona-xtrabackup',
    'color_accent': 'grey',
    'color_primary': 'orange',
    'version_dropdown': True,
    'version_dropdown_text': 'Versions',
    'version_info': {
        "2.4": "https://pxb-24.netlify.app/",
        "8.0": "https://pxb-80.netlify.app/",
        "Latest": "https://pxb-80.netlify.app/"
    },
}
html_logo = '../_images/percona-logo.svg'
html_favicon = '../_images/percona_favicon.ico'
pygments_style = 'emacs'
gitstamp_fmt = "%b %d, %Y"
copybutton_prompt_text = '$'

