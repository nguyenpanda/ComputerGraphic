# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Wextra -std=c++20

# Directories
SRC_DIR = src
TEST_DIR = testcase
DIGIT_DIR = test_application/digit_recognizer
DRAW_DIR = src/Draw/GraphicObject
UTILITY_DIR = src/Utility
PIXEL_DIR = src/PixelScreen
IMG_PROCESSING_DIR = src/ImageProcessing
TEST_IMG_DIR = testcase/Image
TEST_OBJ_DIR = testcase/Object
TEST_SCR_DIR = testcase/Screen

# Source files
SRCS = main.cpp \
       $(UTILITY_DIR)/cursor.cpp \
       $(UTILITY_DIR)/color.cpp \
       $(UTILITY_DIR)/performance.cpp \
       $(PIXEL_DIR)/Pixel.cpp \
       $(PIXEL_DIR)/ScreenSetting.cpp \
       $(PIXEL_DIR)/Screen.cpp \
       $(IMG_PROCESSING_DIR)/Image/BaseImage.cpp \
       $(IMG_PROCESSING_DIR)/Image/Bitmap.cpp \
       $(DRAW_DIR)/Object.cpp \
       $(DRAW_DIR)/Line.cpp \
       $(DRAW_DIR)/Circle.cpp \
       $(DRAW_DIR)/Rectangle.cpp \
       $(DIGIT_DIR)/Dataset.cpp \
       $(TEST_DIR)/testcase.cpp \
       $(TEST_IMG_DIR)/test_Bitmap.cpp \
       $(TEST_OBJ_DIR)/test_Circle.cpp \
       $(TEST_OBJ_DIR)/test_Line.cpp \
       $(TEST_OBJ_DIR)/test_Rectangle.cpp \
       $(TEST_SCR_DIR)/test_changeAt.cpp \
       $(TEST_SCR_DIR)/test_draw.cpp \
       $(TEST_SCR_DIR)/test_operator.cpp \
       $(TEST_SCR_DIR)/test_plot.cpp

# Header files
HDRS = main.h \
       custom_test.h \
       src/GraphicScreen.h \
       $(UTILITY_DIR)/cursor.h \
       $(UTILITY_DIR)/color.h \
       $(UTILITY_DIR)/performance.h \
       $(UTILITY_DIR)/PriorityQueue.h \
       $(PIXEL_DIR)/Pixel.h \
       $(PIXEL_DIR)/ScreenSetting.h \
       $(PIXEL_DIR)/Screen.h \
       $(IMG_PROCESSING_DIR)/Image.h \
       $(IMG_PROCESSING_DIR)/Image/BaseImage.h \
       $(IMG_PROCESSING_DIR)/Image/Bitmap.h \
       $(DRAW_DIR)/GraphicObject.h \
       $(DRAW_DIR)/Object.h \
       $(DRAW_DIR)/Line.h \
       $(DRAW_DIR)/Circle.h \
       $(DRAW_DIR)/Rectangle.h \
       $(TEST_DIR)/testcase.h \
       $(TEST_IMG_DIR)/test_Bitmap.h \
       $(TEST_OBJ_DIR)/test_Circle.h \
       $(TEST_OBJ_DIR)/test_Line.h \
       $(TEST_OBJ_DIR)/test_Rectangle.h \
       $(TEST_SCR_DIR)/test_changeAt.h \
       $(TEST_SCR_DIR)/test_draw.h \
       $(TEST_SCR_DIR)/test_operator.h \
       $(TEST_SCR_DIR)/test_plot.h \
       $(DIGIT_DIR)/Dataset.h

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable name
EXEC = ComputerGraphic

# Default target
all: $(EXEC)

# Link the executable
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJS)

# Compile each source file to an object file
%.o: %.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up the build
clean:
	rm -f $(OBJS) $(EXEC)

# Phony targets
.PHONY: all clean