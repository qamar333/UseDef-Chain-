#include "llvm/Pass.h"
#include "llvm/IR/Module.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/Transforms/IPO/PassManagerBuilder.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Instruction.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/User.h"
#include "llvm/IR/Use.h"
#include "llvm/IR/Value.h"
#include "llvm/Pass.h"
#include "llvm/DebugInfo.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/ADT/StringRef.h"


using namespace llvm;
using namespace std;

namespace {
	struct InstPass : public ModulePass {
		static char ID;
		//ofstream *outputFile;
		InstPass() : ModulePass(ID) {}

		virtual bool runOnModule(Module &M) {
        		for (auto& F : M) {
				//errs() << "\tFunction: " << F.getName() << "\n";

				for (auto& BB : F) {
					//  errs() << "\t\tBasic Block: " << BB.getName() << "\n";

					for (auto& I : BB) {
						//    errs() << "\t\t\tInstruction: " << I.getOpcodeName() <<"\n";

						//if(DILocation *Loc =const_cast<Type*> (I.getDebugLoc())){
						

						//}


						//if(isa<LoadInst>(&I)){
						for (Value::use_iterator i =I.use_begin(), e = I.use_end(); i != e; ++i){
							//outputFile = new std::ofstream();
							//outputFile->open("Data.txt", std::ios_base::app);
                                			//Value *v = *i;
							int index = isa<StoreInst>(I) ? 1 : 0;
							Value* operand = I.getOperand(index);
                                			if (Instruction *Inst = dyn_cast<Instruction>(*i)) {

                                				errs() << "\t\t\t\t Instruction is used in here: ";
                                				errs() << operand->getName() << '\n';
								//*outputFile<<operand->getName()<<"\n";
								unsigned line=I.getDebugLoc().getLine();
								errs()<<"Line no : "<<line;
							}
						}	

			//}

			



//if( *Inst->isCast(unsigned OpCode)){isCast (unsigned OpCode)
		    
						errs() << "\t\t\t\t ***********Def*********** : " ;
						for (User::op_iterator i = I.op_begin(), e = I.op_end(); i != e; ++i) {
							int index = isa<StoreInst>(I) ? 1 : 0;
							Value* operand = I.getOperand(index);
                                			//Value *v = *i;
                                			Instruction *vi = dyn_cast<Instruction>(*i);
                                			//errs()<<v->getName()<<',';
				
							errs() << "\t\t\t\t Instruction is Defined here: ";
                                			errs() << operand->getName() << '\n';
							unsigned line=I.getDebugLoc().getLine();
							errs()<<"Line no : "<<line;
							//errs()<<"\t\t" << *vi;
                				}
					//errs()<<"\n";
            
					}
				}
			}
		return false;
		}
	};
}

char InstPass::ID = 0;
static RegisterPass<InstPass> X("instpass", "Instruction  Pass", false, false);


