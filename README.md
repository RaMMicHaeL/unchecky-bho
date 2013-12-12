This project is an attempt for an Internet Explorer [Browser Helper 
Object (BHO)](http://en.wikipedia.org/wiki/Browser_Helper_Object) for 
the [Unchecky](http://unchecky.com/) program. 

For more information, please see the blog post [Bringing Unchecky to 
the web](http://rammichael.com/bringing-unchecky-to-the-web).

Status
------

Currently, only [Adobe Reader](http://get.adobe.com/reader/) and [Adobe 
Flash Player](http://get.adobe.com/flashplayer/) pages are supported.
The offer checkbox is being Unchecked with a timer.

Building
--------

The project is being developed using Visual Studio 2013. Older versions 
of Visual Studio might be supported as well. 

Registering
-----------

After building the BHO, run regsvr32 as administrator with the dll as 
the first argument:

	regsvr32 unchecky_bho_32.dll

For the 64-bit version:

	regsvr32 unchecky_bho_64.dll
