class Spreadsheet {
public:
    vector<vector<int>>sheet;
    Spreadsheet(int rows) {
        sheet.resize(rows+1,vector<int>(26,0));
    }
    
    void setCell(string cell, int value) {
        sheet[stoi(cell.substr(1,cell.length()-1))][(int)(cell[0]-'A')]=value;
    }
    
    void resetCell(string cell) {
        sheet[stoi(cell.substr(1,cell.length()-1))][(int)(cell[0]-'A')]=0;
    }
    
    int getValue(string formula) {
        int inta=0,intb=0;
        int k=formula.find('+');
        if(formula[1]>='A' && formula[1]<='Z'){
            inta=sheet[stoi(formula.substr(2,k-2))][(int)(formula[1]-'A')];
           }
        else{
            inta=stoi(formula.substr(1,k-1));
        }
         if(formula[k+1]>='A' && formula[k+1]<='Z'){
            intb=sheet[stoi(formula.substr(k+2,formula.length()-k-2))][(int)(formula[k+1]-'A')];
           }
        else{
            intb=stoi(formula.substr(k+1,formula.length()-k-1));
        }
        return inta+intb;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */