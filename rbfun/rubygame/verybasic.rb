$: << File.expand_path('../lib', __FILE__)

require 'java'
require 'lwjgl.jar'
require 'slick.jar'

java_import org.newdawn.slick.BasicGame
java_import org.newdawn.slick.GameContainer
java_import org.newdawn.slick.Graphics
java_import org.newdawn.slick.Input
java_import org.newdawn.slick.SlickException
java_import org.newdawn.slick.AppGameContainer

class RubGame < BasicGame
	def render(container, graphics)
		graphics.draw_string('Jruby Game Demo (Esc to exit)', 8, container.height - 30)
	end

def init(container)

end

def update(container, delta)
#Grab input and exit if escape is pressed
input = container.get_input
container.exit if input.is_key_down(Input::KEY_ESCAPE)
end
end

app = AppGameContainer.new(RubGame.new('H66 DEMO'))
app.set_display_mode(640, 480, false)
app.start
