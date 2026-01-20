class Solution {
    
    
    string doc;
    stack<char> redoStack;
  public:
    void append(char x) {
        // append x into document
        doc.push_back(x);
        
        // When a new character is manually appended, 
        // the redo history is usually invalidated in standard editors.
        while (!redoStack.empty()) {
            redoStack.pop();
        }
    }

    void undo() {
        // undo last change
        if (!doc.empty()) {
            char lastChar = doc.back();
            doc.pop_back();
            // Save the removed character to the redo stack
            redoStack.push(lastChar);
        }
    }

    void redo() {
        // redo changes
        if (!redoStack.empty()) {
            char charToRestore = redoStack.top();
            redoStack.pop();
            // Restore the character to the document
            doc.push_back(charToRestore);
        }
    }

    string read() {
        // read the document
        return doc;
    }
};