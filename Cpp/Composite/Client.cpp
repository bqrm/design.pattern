/***************************************
 * FileName:	
 * Project:		
 * Function:	
 * Creator:		bqrmtao@gmail.com
 * DateTime:	
***************************************/

#include "Employee.h"
#include "WorkGroup.h"

int main(int argc, char** argv)
{
	CWorkGroup *pCompany = new CWorkGroup();

    pCompany->AddSubGroup(new CEmployee());

    CEmployee* pLeaf1 = new CEmployee();
    CEmployee* pLeaf2 = new CEmployee();

	// meaningless operation
    pLeaf1->AddSubGroup(pLeaf2);
    pLeaf1->RemoveSubGroup(pLeaf2);

	// leaf node doing job
	pLeaf1->JobDescription();
	printf("\n\n");

    CWorkGroup* pDepartment = new CWorkGroup();
    pDepartment->AddSubGroup(pLeaf1);
	pDepartment->AddSubGroup(pLeaf2);
	pDepartment->JobDescription();
	printf("\n\n");

    pCompany->AddSubGroup(pDepartment);
	pCompany->JobDescription();
	printf("\n\n");

    pDepartment->GetSubGroup(0)->JobDescription();
	printf("\n\n");

    pDepartment->RemoveSubGroup(pLeaf1);
	pDepartment->GetSubGroup(0)->JobDescription();

	printf("press any key to exit...\n");
	getchar();
}