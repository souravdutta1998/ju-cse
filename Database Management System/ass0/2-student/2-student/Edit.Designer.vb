<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class Edit
    Inherits _2_student.Main

    'Form overrides dispose to clean up the component list.
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.  
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Me.Label1 = New System.Windows.Forms.Label
        Me.rolltext1 = New System.Windows.Forms.TextBox
        Me.Label2 = New System.Windows.Forms.Label
        Me.optioncombo = New System.Windows.Forms.ComboBox
        Me.editButton = New System.Windows.Forms.Button
        Me.result1 = New System.Windows.Forms.Label
        Me.Label3 = New System.Windows.Forms.Label
        Me.input = New System.Windows.Forms.TextBox
        Me.cancButton = New System.Windows.Forms.Button
        Me.result0 = New System.Windows.Forms.Label
        Me.SuspendLayout()
        '
        'Label1
        '
        Me.Label1.AutoSize = True
        Me.Label1.Location = New System.Drawing.Point(16, 16)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(53, 13)
        Me.Label1.TabIndex = 0
        Me.Label1.Text = "Enter Roll"
        '
        'rolltext1
        '
        Me.rolltext1.Location = New System.Drawing.Point(123, 12)
        Me.rolltext1.Name = "rolltext1"
        Me.rolltext1.Size = New System.Drawing.Size(100, 20)
        Me.rolltext1.TabIndex = 1
        '
        'Label2
        '
        Me.Label2.AutoSize = True
        Me.Label2.Location = New System.Drawing.Point(16, 41)
        Me.Label2.Name = "Label2"
        Me.Label2.Size = New System.Drawing.Size(101, 13)
        Me.Label2.TabIndex = 2
        Me.Label2.Text = "Choose what to edit"
        '
        'optioncombo
        '
        Me.optioncombo.FormattingEnabled = True
        Me.optioncombo.Items.AddRange(New Object() {"Name", "Address", "Phone"})
        Me.optioncombo.Location = New System.Drawing.Point(123, 38)
        Me.optioncombo.Name = "optioncombo"
        Me.optioncombo.Size = New System.Drawing.Size(121, 21)
        Me.optioncombo.TabIndex = 3
        '
        'editButton
        '
        Me.editButton.Location = New System.Drawing.Point(52, 101)
        Me.editButton.Name = "editButton"
        Me.editButton.Size = New System.Drawing.Size(75, 23)
        Me.editButton.TabIndex = 4
        Me.editButton.Text = "EDIT"
        Me.editButton.UseVisualStyleBackColor = True
        '
        'result1
        '
        Me.result1.AutoSize = True
        Me.result1.Location = New System.Drawing.Point(184, 141)
        Me.result1.Name = "result1"
        Me.result1.Size = New System.Drawing.Size(0, 13)
        Me.result1.TabIndex = 5
        '
        'Label3
        '
        Me.Label3.AutoSize = True
        Me.Label3.Location = New System.Drawing.Point(16, 67)
        Me.Label3.Name = "Label3"
        Me.Label3.Size = New System.Drawing.Size(90, 13)
        Me.Label3.TabIndex = 6
        Me.Label3.Text = "Enter edited input"
        '
        'input
        '
        Me.input.Location = New System.Drawing.Point(123, 64)
        Me.input.Name = "input"
        Me.input.Size = New System.Drawing.Size(100, 20)
        Me.input.TabIndex = 7
        '
        'cancButton
        '
        Me.cancButton.Location = New System.Drawing.Point(164, 100)
        Me.cancButton.Name = "cancButton"
        Me.cancButton.Size = New System.Drawing.Size(75, 23)
        Me.cancButton.TabIndex = 8
        Me.cancButton.Text = "CANCEL"
        Me.cancButton.UseVisualStyleBackColor = True
        '
        'result0
        '
        Me.result0.AutoSize = True
        Me.result0.Location = New System.Drawing.Point(13, 141)
        Me.result0.Name = "result0"
        Me.result0.Size = New System.Drawing.Size(0, 13)
        Me.result0.TabIndex = 9
        '
        'Edit
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(390, 316)
        Me.Controls.Add(Me.result0)
        Me.Controls.Add(Me.cancButton)
        Me.Controls.Add(Me.input)
        Me.Controls.Add(Me.Label3)
        Me.Controls.Add(Me.result1)
        Me.Controls.Add(Me.editButton)
        Me.Controls.Add(Me.optioncombo)
        Me.Controls.Add(Me.Label2)
        Me.Controls.Add(Me.rolltext1)
        Me.Controls.Add(Me.Label1)
        Me.Name = "Edit"
        Me.Text = "Edit"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents Label1 As System.Windows.Forms.Label
    Friend WithEvents rolltext1 As System.Windows.Forms.TextBox
    Friend WithEvents Label2 As System.Windows.Forms.Label
    Friend WithEvents optioncombo As System.Windows.Forms.ComboBox
    Friend WithEvents editButton As System.Windows.Forms.Button
    Friend WithEvents result1 As System.Windows.Forms.Label
    Friend WithEvents Label3 As System.Windows.Forms.Label
    Friend WithEvents input As System.Windows.Forms.TextBox
    Friend WithEvents cancButton As System.Windows.Forms.Button
    Friend WithEvents result0 As System.Windows.Forms.Label
End Class
