solution "B2D"

	-- Build Configurations
	configurations {"Debug", "Release"}
	
	project "B2D"

		-- Project Settings
		kind "StaticLib"
		language "C++"
		location "B2D_Build"
		defines {"GLEW_STATIC", "FTGL_LIBRARY_STATIC"}
		files {"./Source/**.h", "./Source/**.cpp"}

		-- Set Windows Specific Options
		if os.get() == "windows" then
		
			includedirs {"./include*", os.getenv ("PYTHONINCLUDE")}
			libdirs {"./lib*", os.getenv ("PYTHONLIBS")}
			links {"glew32s", "GLFW", "opengl32", "audiere", "FreeImage", "ftgl_static", "VectorMathLib", "python26"}
		end

		-- Set Linux Specific Options
		if os.get() == "linux" then

			buildoptions "-std=c++0x"
			includedirs {"./include*", os.getenv ("PYTHONINCLUDE").."*"}
			libdirs {"./lib*", os.getenv ("PYTHONLIBS").."*"}
			links {"libftgl", "libGLEW", "libglfw", "GL", "libfreeimage", "libfreetype", "libVML", "libaudiere", "libpython2.7", "libdl", "libutil"}
		end

		-- Debug Settings
		--configuration "Debug"

			--defines "DEBUG"
			--flags "Symbols"

		-- Release Settings
		--configuration "Release"
			
			--defines "NDEBUG"
			--flags "Optimize"
