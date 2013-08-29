solution "B2D"
	configurations {"Debug", "Release"}
	
	project "B2D"
		kind "StaticLib"
		language "C++"
		location "B2D_Build"
		defines {"GLEW_STATIC", "FTGL_LIBRARY_STATIC"}
		files {"./Source/**.h", "./Source/**.cpp"}
		includedirs {"./include*", os.getenv("PYTHONHOME").."/include*"}
		libdirs {"./lib*", os.getenv("PYTHONHOME").."/libs*"}
		links {"glew32mxs", "glew32s", "GLFW", "opengl32", "audiere", "FreeImage", "ftgl_static", "VectorMathLib", "python26"}