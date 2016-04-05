#include "gtest/gtest.h"
#include <stdlib.h>
#include </home/anmol/git/ism/ism.cpp>

Guard g;
VehicleDatabase v;
Vehicle ve;

TEST(GuardPositioning, canSetNumericGuardPosition) {
	int position = int(rand());
	g.setPositioning(position);
	EXPECT_EQ(position, g.getPositioning());
}

TEST(GuardPositioning, canSetProperNumericGuardPosition) {
	int position = rand()%4;
	g.setPositioning(position);
	EXPECT_EQ(position, g.getPositioning());
	position += 4;
	g.setPositioning(position);
	EXPECT_ANY_THROW();
}

TEST(GuardPositioning, cannotSetAlphabeticGuardPosition) {
	g.setPositioning('d');
	ASSERT_ANY_THROW();
}

TEST(VehicleDatabaseEntry, setVehicleSlot) {
	for(int i=0;i<100;i++)
	{
		v.setSlot();
		EXPECT_EQ(i, v.getSlot());
	}

	// Rolling Back changes
	for(int i=0;i<100;i++)
	{
		v.freeSlot(i);
	}
}

TEST(VehicleDatabaseExit, getFreeSlotAfterSetting) {
	int c = check;
	int slot_number = v.setSlot();
	v.freeSlot(slot_number);
	EXPECT_EQ(c, check);
	EXPECT_EQ(0, slotcount[slot_number]);
}

TEST(VehicleDatabaseExit, getFreeSlotBeforeSetting) {
	v.freeSlot(0);
	EXPECT_EQ(0, slotcount[0]);
	EXPECT_EQ(0, check);
}

TEST(VehicleStatus, checkStatus) {
	EXPECT_EQ(0, ve.isStatusIn());
}

TEST(VehicleMarked, checkIfMarked) {
	EXPECT_EQ(0, ve.ifMarked());
}

TEST(VehicleMarked, checkIfUnmarked) {
	ve.mark = 1;
	EXPECT_EQ(0, ve.ifUnmarked());
}

TEST(VehicleColor, checkColoredProperly) {
	string color = "Blue";
	v.setColor(color);
	EXPECT_EQ(color, v.getColor());

}

TEST(VehicleDriverName, checkDriverName) {
	string name = "Tejas";
	v.setDriverName(name);
	EXPECT_EQ(name, v.getDriverName());

}

TEST(VehicleNumber, checkValidRegistrationNumber) {
	string number = "RJ 19 CC 2356";
	v.setRegistrationNo(number);
	EXPECT_EQ(number, v.getRegistrationNo());

}

TEST(VehicleNumber, checkInValidRegistrationNumber) {
	string number = "2356 GJ RQ";
	v.setRegistrationNo(number);
	EXPECT_ANY_THROW(number);

}

// int main(int argc, char **argv) {
//   ::testing::InitGoogleTest(&argc, argv);
//   return RUN_ALL_TESTS();
// }
