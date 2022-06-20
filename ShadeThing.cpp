class ShadeThing {
	private:
		int value_limits[2];
		int value_stepMin;
		int value_stepStep;
		int value;
		bool isIncrementing;
	public:
		ShadeThing(int *value_limits, int value_stepMin = 0, int value_stepStep = 1){
			this->value = value_limits[0];
			for (int i = 0; i < 2; i++){
				this->value_limits[i] = value_limits[i];
			}
			this->value_stepMin = value_stepMin;
			this->value_stepStep = value_stepStep;

			if (this->value_stepMin < 0){
				throw "Minimum value for `value_stepMin` is 0。";
			}
			if (this->value_stepStep < 0){
				throw "Minimum value for `value_stepStep` is 0。";
			}
		}

		int iterate(){
			if (this->value <= value_limits[0]){
				this->isIncrementing = true;
			}
			if (this->value >= value_limits[1]){
				this->isIncrementing = false;
			}

			this->value += (
				this->isIncrementing? (+1):(-1)
			) * (
				(
					rand() % (this->value_stepStep + 1)
				) + this->value_stepMin
			);

			if (this->value < this->value_limits[0]){
				this->value = this->value_limits[0];
			}
			if (this->value > this->value_limits[1]){
				this->value = this->value_limits[1];
			}
			return this->value;
		}
};
