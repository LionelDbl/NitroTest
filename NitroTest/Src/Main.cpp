#include <iostream>

#include "CommandLine.h"
#include "FileLoader.h"
#include "IntersectionsCalculator.h"
#include "OutputGenerator.h"
#include "ExceptionEx.h"

const std::string outputFileName = "output.txt";

int main(int argc, char* argv[])
{
   try
   {
      CommandLine cmdLine;
      cmdLine.Parse(argc, argv);
      
      std::string fileName = cmdLine.GetFileName();
      std::list<Rectangle> rectangles;
      FileLoader fileLoader;
      fileLoader.ExtractRectangles(fileName, rectangles);
            
      std::list<Intersection> intersections;
      IntersectionsCalculator calculator;
      calculator.FindIntersections(rectangles, intersections);

      std::string outputName = cmdLine.GetCurrentPath();
      outputName += outputFileName;
      OutputGenerator output(outputName);
      output.Generate(rectangles, intersections);
   }
   catch (bad_arg&)
   {
      std::cout << "bad argument: Please specify the name of the JSON file" << std::endl;
   }
   catch (file_notfound& e)
   {
      std::cout << "JSON file not found: " << e.GetFileName() << std::endl;
   }
   catch (file_notvalid&)
   {
      std::cout << "JSON file not valid" << std::endl;
   }
   catch (dim_notvalid&)
   {
      std::cout << "dimension not valid" << std::endl;
   }
   catch (std::exception& e)
   {
      std::cout << "Error occurred during execution: " << e.what() << std::endl;
   }
   catch (...)
   {
      std::cout << "Unexpected error during execution" << std::endl;
   }

   return 0;
}