#!/bin/bash

cd css

xxd -i custom_window.css >  custom_window_css.h
xxd -i custom_titlebar.css >  custom_titlebar_css.h
xxd -i custom_toolbar.css >  custom_toolbar_css.h

cd ..
