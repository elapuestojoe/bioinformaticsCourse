##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=multipleSequenceAlignment
ConfigurationName      :=Debug
WorkspacePath          :=E:/CppPlayground/bio
ProjectPath            :=E:/CppPlayground/bio/multipleSequenceAlignment
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=kevin
Date                   :=08/02/2019
CodeLitePath           :=E:/Aplicaciones/CodeLite
LinkerName             :=E:/Aplicaciones/TDM-GCC-64/bin/g++.exe
SharedObjectLinkerName :=E:/Aplicaciones/TDM-GCC-64/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="multipleSequenceAlignment.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=E:/Aplicaciones/TDM-GCC-64/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := E:/Aplicaciones/TDM-GCC-64/bin/ar.exe rcu
CXX      := E:/Aplicaciones/TDM-GCC-64/bin/g++.exe
CC       := E:/Aplicaciones/TDM-GCC-64/bin/gcc.exe
CXXFLAGS :=  -g -O0 -Wall  -std=c++11 $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := E:/Aplicaciones/TDM-GCC-64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=E:\Aplicaciones\CodeLite
Objects0=$(IntermediateDirectory)/stringUtilities.cpp$(ObjectSuffix) $(IntermediateDirectory)/needlemanWunsch.cpp$(ObjectSuffix) $(IntermediateDirectory)/blossum.cpp$(ObjectSuffix) $(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/sequenceUtilities.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/stringUtilities.cpp$(ObjectSuffix): stringUtilities.cpp $(IntermediateDirectory)/stringUtilities.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/CppPlayground/bio/multipleSequenceAlignment/stringUtilities.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/stringUtilities.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/stringUtilities.cpp$(DependSuffix): stringUtilities.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/stringUtilities.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/stringUtilities.cpp$(DependSuffix) -MM stringUtilities.cpp

$(IntermediateDirectory)/stringUtilities.cpp$(PreprocessSuffix): stringUtilities.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/stringUtilities.cpp$(PreprocessSuffix) stringUtilities.cpp

$(IntermediateDirectory)/needlemanWunsch.cpp$(ObjectSuffix): needlemanWunsch.cpp $(IntermediateDirectory)/needlemanWunsch.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/CppPlayground/bio/multipleSequenceAlignment/needlemanWunsch.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/needlemanWunsch.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/needlemanWunsch.cpp$(DependSuffix): needlemanWunsch.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/needlemanWunsch.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/needlemanWunsch.cpp$(DependSuffix) -MM needlemanWunsch.cpp

$(IntermediateDirectory)/needlemanWunsch.cpp$(PreprocessSuffix): needlemanWunsch.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/needlemanWunsch.cpp$(PreprocessSuffix) needlemanWunsch.cpp

$(IntermediateDirectory)/blossum.cpp$(ObjectSuffix): blossum.cpp $(IntermediateDirectory)/blossum.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/CppPlayground/bio/multipleSequenceAlignment/blossum.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/blossum.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/blossum.cpp$(DependSuffix): blossum.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/blossum.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/blossum.cpp$(DependSuffix) -MM blossum.cpp

$(IntermediateDirectory)/blossum.cpp$(PreprocessSuffix): blossum.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/blossum.cpp$(PreprocessSuffix) blossum.cpp

$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/CppPlayground/bio/multipleSequenceAlignment/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/sequenceUtilities.cpp$(ObjectSuffix): sequenceUtilities.cpp $(IntermediateDirectory)/sequenceUtilities.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/CppPlayground/bio/multipleSequenceAlignment/sequenceUtilities.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/sequenceUtilities.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/sequenceUtilities.cpp$(DependSuffix): sequenceUtilities.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/sequenceUtilities.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/sequenceUtilities.cpp$(DependSuffix) -MM sequenceUtilities.cpp

$(IntermediateDirectory)/sequenceUtilities.cpp$(PreprocessSuffix): sequenceUtilities.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/sequenceUtilities.cpp$(PreprocessSuffix) sequenceUtilities.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


