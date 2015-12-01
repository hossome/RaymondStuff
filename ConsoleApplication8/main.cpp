//*********************************************************************
//=====================================================================

//Use the following in the main file :


int compareValues(const PTR_ROMAN &left, const PTR_ROMAN &right)
{
	int diff = left->getValue() - right->getValue();
	if (diff == 0)
		diff = left->getRomString().compare(right->getRomString());
	return diff;
}

int compareRomStrings(const PTR_ROMAN &left, const PTR_ROMAN &right)
{
	int diff = left->getRomString().compare(right->getRomString());
	if (diff == 0)
		diff = left->getValue() - right->getValue();
	return diff;
}

int HashString(const string & key) // USE THIS OR YOUR OWN
{
	unsigned int k, retVal = 0;

	for (k = 0; k < key.length(); k++)
		retVal = 37 * retVal + key[k];


	return retVal;
}

int Hash(int key) // Not used for HW#5
{
	return key;
}

// YOU MUST CALL THIS as specified in HW#5

void testHashTables(HashTable<PTR_ROMAN> *ptableSC,
	HashTable<PTR_ROMAN> *ptableQP)
{
	RomanNumeral* romToDeleteSC, *romToDeleteQP;
	int randInt;
	RomanNumeral targetRom;
	bool getReturnSC, getReturnQP;

	// find a value in the hashtables:
	do
	{
		randInt = (rand() % (5000)) + 1;
		targetRom.setValue(randInt);
		getReturnSC = ptableSC->getEntry(&targetRom, romToDeleteSC);
		getReturnQP = ptableQP->getEntry(&targetRom, romToDeleteQP);
		cout << "Result of calling getEntry for HashSC for " << targetRom.getValue()
			<< ", " << targetRom.getRomString() << " = " << getReturnSC << endl;
		cout << "Result of calling getEntry for HashQP for " << targetRom.getValue()
			<< ", " << targetRom.getRomString() << " = " << getReturnQP << endl;
	} while (!getReturnSC || !getReturnQP);

	// must have found in both:
	cout << "Retrived RomanNumerals in both tables, will try to delete: "
		<< romToDeleteSC->getRomString() << ", "
		<< romToDeleteSC->getValue() << " AND " << romToDeleteQP->getRomString() <<
		", " << romToDeleteQP->getValue() << endl;

	// now try to delete from both tables:
	if (ptableSC->remove(&targetRom))
		cout << "Successfully removed from HashSC: " <<
		targetRom.getValue() << ", " << targetRom.getRomString() << endl;
	else
		cout << "Error: unsuccessful removal from HashSC: " <<
		targetRom.getValue() << ", " << targetRom.getRomString() << endl;

	if (ptableQP->remove(&targetRom))
		cout << "Successfully removed from HashQP: " << targetRom.getRomString() <<
		", " << targetRom.getValue() << endl;
	else
		cout << "Error: unsuccessful removal from HashQP: "
		<< targetRom.getRomString() <<
		", " << targetRom.getValue() << endl;

	delete romToDeleteSC; // may cause problems if your remove function didn't work!
						  // should be same pointer as romToDeleteQP
}

// YOU MUST USE THIS as specified in HW#5

void deletePTR_ROMAN(PTR_ROMAN &param)
{
	if (param != 0)
		delete param;
	param = 0;
}