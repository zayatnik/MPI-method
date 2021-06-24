#include "MyForm.h"
#include "functions.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	MpiMethod::MyForm form;
	Application::Run(% form);
}

System::Void MpiMethod::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	int a = 1, b = 2, c = 1, d = 2;
	int m = Convert::ToInt32(numericUpDownM->Value);
	int n = Convert::ToInt32(numericUpDownN->Value);
	int Nmax = Convert::ToInt32(numericUpDownNiter->Value);
	double Eps = Convert::ToDouble(numericUpDownEps->Value);

	if (MPIradio->Checked)
	{
		if (radioMainTask->Checked)
		{
			answer res1 = Task(a, b, c, d, n, m, Nmax, Eps, 'm');
			answer res2 = Task(a, b, c, d, 2 * n, 2 * m, Nmax, Eps, 'm');
			double eps = EpsInMainTask(res1.V, res2.V);

			MessageBox::Show("Для решения задачи использована сетка с числом разбиений по x n = " + Convert::ToString(n)
				+ " и числом разбиений по y m = " + Convert::ToString(m) + ". Применялся метод простой итерации. \n\nПараметр метода: Tau = "
				+ Convert::ToString(res1.tau) + "\n\n" +
				"На решение задачи затрачено: N = " + Convert::ToString(res1.Niter) + "\n\n" + "Общее время задачи: " +
				Convert::ToString(res1.time) + "\n\n" + "В среднем за одну итерацию: " + Convert::ToString(res1.time_iter) + "\n\n" +
				"Достигнутая точность метода: " + Convert::ToString(res1.eps) + "\n\n\n\n" + "На решение задачи с половинным шагом затрачено: N = "
				+ Convert::ToString(res2.Niter) + "\n\n" + "Параметр метода : Tau = " + Convert::ToString(res1.tau) + "\n\n" +
				"Общее время задачи: " + Convert::ToString(res2.time) + "\n\n"+ "В среднем за одну итерацию: " + Convert::ToString(res2.time_iter) +
				"\n\n" + "Достигнутая точность метода: " + Convert::ToString(res2.eps) + "\n\n\n" +
				"Максимальная разность двух приближений составила: " + Convert::ToString(eps));

			if (TableV->Checked)
			{
				dataGridView1->Rows->Clear();
				dataGridView1->ColumnCount = res1.V[0].size() + 2;
				dataGridView1->Rows->Add();
				dataGridView1->Rows->Add();
				dataGridView1->Rows[0]->Cells[1]->Value = "i";
				dataGridView1->Rows[1]->Cells[0]->Value = "j";
				dataGridView1->Rows[1]->Cells[1]->Value = "Y / X";

				for (int i = 0; i < n + 1; i++)
					dataGridView1->Rows[0]->Cells[2 + i]->Value = i;

				for (int i = 2; i < res1.V.size() + 2; i++)
				{
					dataGridView1->Rows->Add();
					for (int j = 2; j < res1.V[0].size() + 2; j++)
					{
						dataGridView1->Rows[i]->Cells[j]->Value = res1.V[i - 2][j - 2];
					}
				}

				for (int j = 0; j < m + 1; j++)
					dataGridView1->Rows[2 + j]->Cells[0]->Value = j;
			}

			if (TableV2->Checked)
			{
				dataGridView1->Rows->Clear();
				dataGridView1->ColumnCount = res2.V[0].size() + 2;
				dataGridView1->Rows->Add();
				dataGridView1->Rows->Add();
				dataGridView1->Rows[0]->Cells[1]->Value = "i";
				dataGridView1->Rows[1]->Cells[0]->Value = "j";
				dataGridView1->Rows[1]->Cells[1]->Value = "Y / X";

				for (int i = 0; i < 2 * n + 1; i++)
					dataGridView1->Rows[0]->Cells[2 + i]->Value = i;

				for (int i = 2; i < res2.V.size() + 2; i++)
				{
					dataGridView1->Rows->Add();
					for (int j = 2; j < res2.V[0].size() + 2; j++)
					{
						dataGridView1->Rows[i]->Cells[j]->Value = res2.V[i - 2][j - 2];
					}
				}

				for (int j = 0; j < 2 * m + 1; j++)
					dataGridView1->Rows[2 + j]->Cells[0]->Value = j;
			}
			
		}


		if (radioTestTask->Checked)
		{
			answer res1 = Task(a, b, c, d, n, m, Nmax, Eps, 't');
			std::vector<std::vector<double>> U;
			U.assign(m + 1, std::vector<double>(n + 1));
			U_test(U, m, n, a, b, c, d);
			double eps = EpsInTestTask(res1.V, U);
			MessageBox::Show("Для решения задачи использована сетка с числом разбиений по x n = " + Convert::ToString(n)
				+ " и числом разбиений по y m = " + Convert::ToString(m) + ". Применялся метод простой итерации. \n\nПараметр метода: Tau = "
				+ Convert::ToString(res1.tau) + "\n\n" +
				"На решение задачи затрачено: N = " + Convert::ToString(res1.Niter) + "\n\n" + "Общее время задачи: " +
				Convert::ToString(res1.time) + "\n\n" + "В среднем за одну итерацию: " + Convert::ToString(res1.time_iter) + "\n\n" +
				"Достигнутая точность метода: " + Convert::ToString(res1.eps) + "\n\n\n\n" + 
				"Тестовая задача решена с точностью: " + Convert::ToString(eps));

			if (TableVtest->Checked)
			{
				dataGridView1->Rows->Clear();
				dataGridView1->ColumnCount = res1.V[0].size() + 2;
				dataGridView1->Rows->Add();
				dataGridView1->Rows->Add();
				dataGridView1->Rows[0]->Cells[1]->Value = "i";
				dataGridView1->Rows[1]->Cells[0]->Value = "j";
				dataGridView1->Rows[1]->Cells[1]->Value = "Y / X";

				for (int i = 0; i < n + 1; i++)
					dataGridView1->Rows[0]->Cells[2 + i]->Value = i;

				for (int i = 2; i < res1.V.size() + 2; i++)
				{
					dataGridView1->Rows->Add();
					for (int j = 2; j < res1.V[0].size() + 2; j++)
					{
						dataGridView1->Rows[i]->Cells[j]->Value = res1.V[i - 2][j - 2];
					}
				}

				for (int j = 0; j < m + 1; j++)
					dataGridView1->Rows[2 + j]->Cells[0]->Value = j;
			}

			if (TableUtest->Checked)
			{
				dataGridView1->Rows->Clear();
				dataGridView1->ColumnCount = res1.V[0].size() + 2;
				dataGridView1->Rows->Add();
				dataGridView1->Rows->Add();
				dataGridView1->Rows[0]->Cells[1]->Value = "i";
				dataGridView1->Rows[1]->Cells[0]->Value = "j";
				dataGridView1->Rows[1]->Cells[1]->Value = "Y / X";

				for (int i = 0; i < n + 1; i++)
					dataGridView1->Rows[0]->Cells[2 + i]->Value = i;

				for (int i = 2; i < U.size() + 2; i++)
				{
					dataGridView1->Rows->Add();
					for (int j = 2; j < U[0].size() + 2; j++)
					{
						dataGridView1->Rows[i]->Cells[j]->Value = U[i - 2][j - 2];
					}
				}

				for (int j = 0; j < m + 1; j++)
					dataGridView1->Rows[2 + j]->Cells[0]->Value = j;
			}

		}

	}

	if (Grad->Checked)
	{
		if (radioMainTask->Checked)
		{
			answer res1 = TaskGrad(a, b, c, d, n, m, Nmax, Eps, 'm');
			answer res2 = TaskGrad(a, b, c, d, 2 * n, 2 * m, Nmax, Eps, 'm');
			double eps = EpsInMainTask(res1.V, res2.V);

			MessageBox::Show("Для решения задачи использована сетка с числом разбиений по x n = " + Convert::ToString(n)
				+ " и числом разбиений по y m = " + Convert::ToString(m) + ". Применялся метод сопряженных градиентов."
				+ "\n\n" +
				"На решение задачи затрачено: N = " + Convert::ToString(res1.Niter / 2) + "\n\n" + "Общее время задачи: " +
				Convert::ToString(res1.time) + "\n\n" + "В среднем за одну итерацию: " + Convert::ToString(res1.time_iter) + "\n\n" +
				"Достигнутая точность метода: " + Convert::ToString(res1.eps) + "\n\n\n\n" + "На решение задачи с половинным шагом затрачено: N = "
				+ Convert::ToString(res2.Niter / 2) + "\n\n" +
				"Общее время задачи: " + Convert::ToString(res2.time) + "\n\n" + "В среднем за одну итерацию: " + Convert::ToString(res2.time_iter) +
				"\n\n" + "Достигнутая точность метода: " + Convert::ToString(res2.eps) + "\n\n\n" +
				"Максимальная разность двух приближений составила: " + Convert::ToString(eps));

			if (TableV->Checked)
			{
				dataGridView1->Rows->Clear();
				dataGridView1->ColumnCount = res1.V[0].size() + 2;
				dataGridView1->Rows->Add();
				dataGridView1->Rows->Add();
				dataGridView1->Rows[0]->Cells[1]->Value = "i";
				dataGridView1->Rows[1]->Cells[0]->Value = "j";
				dataGridView1->Rows[1]->Cells[1]->Value = "Y / X";

				for (int i = 0; i < n + 1; i++)
					dataGridView1->Rows[0]->Cells[2 + i]->Value = i;

				for (int i = 2; i < res1.V.size() + 2; i++)
				{
					dataGridView1->Rows->Add();
					for (int j = 2; j < res1.V[0].size() + 2; j++)
					{
						dataGridView1->Rows[i]->Cells[j]->Value = res1.V[i - 2][j - 2];
					}
				}

				for (int j = 0; j < m + 1; j++)
					dataGridView1->Rows[2 + j]->Cells[0]->Value = j;
			}

			if (TableV2->Checked)
			{
				dataGridView1->Rows->Clear();
				dataGridView1->ColumnCount = res2.V[0].size() + 2;
				dataGridView1->Rows->Add();
				dataGridView1->Rows->Add();
				dataGridView1->Rows[0]->Cells[1]->Value = "i";
				dataGridView1->Rows[1]->Cells[0]->Value = "j";
				dataGridView1->Rows[1]->Cells[1]->Value = "Y / X";

				for (int i = 0; i < 2 * n + 1; i++)
					dataGridView1->Rows[0]->Cells[2 + i]->Value = i;

				for (int i = 2; i < res2.V.size() + 2; i++)
				{
					dataGridView1->Rows->Add();
					for (int j = 2; j < res2.V[0].size() + 2; j++)
					{
						dataGridView1->Rows[i]->Cells[j]->Value = res2.V[i - 2][j - 2];
					}
				}

				for (int j = 0; j < 2 * m + 1; j++)
					dataGridView1->Rows[2 + j]->Cells[0]->Value = j;
			}

		}
	}

	if (radioTestTask->Checked)
	{
		answer res1 = TaskGrad(a, b, c, d, n, m, Nmax, Eps, 't');
		std::vector<std::vector<double>> U;
		U.assign(m + 1, std::vector<double>(n + 1));
		U_test(U, m, n, a, b, c, d);
		double eps = EpsInTestTask(res1.V, U);
		MessageBox::Show("Для решения задачи использована сетка с числом разбиений по x n = " + Convert::ToString(n)
			+ " и числом разбиений по y m = " + Convert::ToString(m) + ". Применялся метод сопряженных градиентов."
			+ "\n\n" +
			"На решение задачи затрачено: N = " + Convert::ToString(res1.Niter) + "\n\n" + "Общее время задачи: " +
			Convert::ToString(res1.time) + "\n\n" + "В среднем за одну итерацию: " + Convert::ToString(res1.time_iter) + "\n\n" +
			"Достигнутая точность метода: " + Convert::ToString(res1.eps) + "\n\n\n\n" +
			"Тестовая задача решена с точностью: " + Convert::ToString(eps));

		if (TableVtest->Checked)
		{
			dataGridView1->Rows->Clear();
			dataGridView1->ColumnCount = res1.V[0].size() + 2;
			dataGridView1->Rows->Add();
			dataGridView1->Rows->Add();
			dataGridView1->Rows[0]->Cells[1]->Value = "i";
			dataGridView1->Rows[1]->Cells[0]->Value = "j";
			dataGridView1->Rows[1]->Cells[1]->Value = "Y / X";

			for (int i = 0; i < n + 1; i++)
				dataGridView1->Rows[0]->Cells[2 + i]->Value = i;

			for (int i = 2; i < res1.V.size() + 2; i++)
			{
				dataGridView1->Rows->Add();
				for (int j = 2; j < res1.V[0].size() + 2; j++)
				{
					dataGridView1->Rows[i]->Cells[j]->Value = res1.V[i - 2][j - 2];
				}
			}

			for (int j = 0; j < m + 1; j++)
				dataGridView1->Rows[2 + j]->Cells[0]->Value = j;
		}

		if (TableUtest->Checked)
		{
			dataGridView1->Rows->Clear();
			dataGridView1->ColumnCount = res1.V[0].size() + 2;
			dataGridView1->Rows->Add();
			dataGridView1->Rows->Add();
			dataGridView1->Rows[0]->Cells[1]->Value = "i";
			dataGridView1->Rows[1]->Cells[0]->Value = "j";
			dataGridView1->Rows[1]->Cells[1]->Value = "Y / X";

			for (int i = 0; i < n + 1; i++)
				dataGridView1->Rows[0]->Cells[2 + i]->Value = i;

			for (int i = 2; i < U.size() + 2; i++)
			{
				dataGridView1->Rows->Add();
				for (int j = 2; j < U[0].size() + 2; j++)
				{
					dataGridView1->Rows[i]->Cells[j]->Value = U[i - 2][j - 2];
				}
			}

			for (int j = 0; j < m + 1; j++)
				dataGridView1->Rows[2 + j]->Cells[0]->Value = j;
		}

	}

	return System::Void();
}
