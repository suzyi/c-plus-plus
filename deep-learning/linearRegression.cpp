#include <torch/torch.h>
#include <iostream>
#include <iomanip>

int main() {
	std::cout << "Linear Regression\n";
	std::cout << "Training on CPU\n";

	// set hyper-parameters
	const int64_t input_size = 1;
	const int64_t output_size = 1;
	const size_t epochs = 60;
	const double learning_rate = 0.0001;

	// generate some data points
	auto x_train = torch::randint(0, 10, { 15, 1 });
	auto y_train = torch::randint(0, 10, { 15, 1 });

	// create the linear model
	torch::nn::Linear model(input_size, output_size);

	// build the optimizer
	torch::optim::SGD optimizer(model->parameters(), torch::optim::SGDOptions(learning_rate));

	// set the output precision
	std::cout << std::fixed << std::setprecision(4);

	// train the model
	for (size_t epoch = 0; epoch != epochs; epoch++) {
		// forward pass
		auto output = model(x_train);
		auto loss = torch::nn::functional::mse_loss(output, y_train);

		// update the weights and biases
		optimizer.zero_grad();
		loss.backward();
		optimizer.step();

		if ((epoch + 1) % 5 == 0) {
			std::cout << "epoch " << (epoch + 1) << "/" << epochs << "\t" <<loss.item<double>() << "\n";
		}
	}

	std::cout << "done!";
}