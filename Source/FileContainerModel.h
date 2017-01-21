//
//  FileContainerModel.h
//  ChuckRacks
//
//  Created by Rodrigo Sena on 4/22/15.
//
//

#ifndef __ChuckRacks__FileContainerModel__
#define __ChuckRacks__FileContainerModel__

#include <stdio.h>
#include "KnobInfo.h"
#include "../JuceLibraryCode/JuceHeader.h"
#include "libchuck.h"
#include "ConsoleGlobal.h"

class FileContainerModel
{
public:
    FileContainerModel( chuck_inst* ck_, AudioProcessor* p_ );
    ~FileContainerModel();

    
    void addShred();
    void removeLastShred();
    void removeShred(int idNumber);
    void replaceShred();
    void removeAllShreds();
    
    std::vector<int> shredIds;

    std::vector<AudioProcessorParameter*> knobParameters;

    void openBrowser();

    void setCanBeEdited( bool shouldEdit ){ canBeEdited = shouldEdit; };
    bool getCanBeEdited(){ return canBeEdited; };
    
    const int getUniqueFCId() { return uniqueFileContainerId; };
    
    CodeDocument& getCodeDocument();
    
    
private:
    
    chuck_inst *ck;
    AudioProcessor* processor;
    
    bool canBeEdited;
    String lastFileLoaded;
    
    ScopedPointer<FileChooser> fileChooser;
    String fileName;
    String filePath;
    
    CodeDocument codeDocument;
    
    int uniqueFileContainerId;



};

#endif /* defined(__ChuckRacks__FileContainerModel__) */
